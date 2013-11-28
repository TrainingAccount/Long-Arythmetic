#include "longnumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

LongNumber createNewLongNumber(int Length) 
{
	LongNumber Result;
	Result.Length = Length;
	Result.Sign = 0;
	
	Result.Digits = (int *) calloc(Length, sizeof(int)); 
	if (Result.Digits == NULL) 
	{
		printf("Memory for creating new number is not allocate.\n");
		exit(1);
	}
	
	return Result;
}

void deleteLongNumber(LongNumber LNumber) 
{
	free(LNumber.Digits);
}

LongNumber CopyLongNumber(LongNumber LNumberForCopying) 
{
	LongNumber Result = createNewLongNumber(LNumberForCopying.Length);
	memcpy(Result.Digits, LNumberForCopying.Digits, sizeof(int) * LNumberForCopying.Length);
	Result.Sign = LNumberForCopying.Sign;
	return Result;
}

LongNumber removingLeadNulls(LongNumber Number) 
{
	int i;
	for (i = Number.Length - 1; i >= 0; --i) 
	{
		if (Number.Digits[i] == 0)
			Number.Length--;
		else
			break;
	}
	return Number;
}

LongNumber readingLongNumberFromFile(const char *Name) 
{
	LongNumber Result;
	char SignCharacter, IntBuffer[9];
	int Size, Sign, Offset, Count = 0, Delimiter;

	FILE *FileForInput = fopen(Name, "r+");
	if (FileForInput == NULL) 
	{
		printf("Can\'t open file for reading number. %s\n", Name);
		exit(1);
	}

	fread(&SignCharacter, 1, 1, FileForInput);
	if (SignCharacter == '-')
		Sign = 1; 
	else
		Sign = 0;
	Result.Sign = Sign;

	fseek(FileForInput, 0, SEEK_END);
	Size = ftell(FileForInput) - Sign;
	fseek(FileForInput, Sign, SEEK_SET);
	Result = createNewLongNumber(ceil(Size / 8.));
	
	Offset = Size % 8;
	int i;
	for (i = Result.Length - 1; i >= 0; --i) 
	{
		if (Offset == 0) 
			Count = 8;
		else 
		{
			Count = Offset;
			Offset = 0;
		}
		Delimiter = fread(IntBuffer, 1, Count, FileForInput);
		IntBuffer[Delimiter] = 0;
		Result.Digits[i] = atoi(IntBuffer);
	}

	fclose(FileForInput);
	return removingLeadNulls(Result);
}

LongNumber readingLongNumberFromString (const char *StringName) 
{
	LongNumber Result;
	char SignCharacter, IntBuffer[9];
	int Size, Sign, Offset, Count = 0;

	strncpy (SignCharacter, StringName, 1);
	if (SignCharacter == '-')
		Sign = 1; 
	else
		Sign = 0;
	
	Size = strlen (StringName) - Sign;
	Result = createNewLongNumber(ceil(Size / 8.));
	Result.Sign = Sign;
	
	Offset = Size % 8;
	int i, k = 0, m;
	for (i = Result.Length - 1; i >= 0; --i) 
	{
		if (Offset == 0) 
			Count = 8;
		else 
		{
			Count = Offset;
			Offset = 0;
		}
		
		if (!Sign)
		{
			strcpy (IntBuffer, SignCharacter);
			Count--;
			k++;
			Sign = !Sign;
		}
		
		m = Count;
		IntBuffer[Сount] = 0;
		while (Count)
		{
			IntBuffer[m - Count] = StringName[k];
			k++;
			Count--;
		}
		
		Result.Digits[i] = atoi(IntBuffer);
	}

	return removingLeadNulls(Result);
}

void writingLongNumberToFile(const char *Name, LongNumber Number) 
{
	FILE *FileForOutput = fopen(Name, "w+");
	
	if (FileForOutput == NULL) 
	{
		printf("Can\'t open file for writing number \n");
		return;
	}
	
	if (Number.Length == 0) 
	{
		fprintf(FileForOutput, "0");
	} 
	else 
	{
		if (Number.Sign) 
		{
			fprintf(FileForOutput, "-");
		}
		fprintf(FileForOutput, "%d", Number.Digits[Number.Length - 1]);
		int i;
		for (i = Number.Length - 2; i >= 0; --i) 
		{
			fprintf(FileForOutput, "%.8d", Number.Digits[i]);
		}
	}
	
	fclose(FileForOutput);
}

void writingLongNumberToString(LongNumber Number) 
{
	if (Number.Length == 0) 
	{
		printf("0");
	} 
	else 
	{
		if (Number.Sign) 
		{
			printf("-");
		}
		printf("%d", Number.Digits[Number.Length - 1]);
		
		int i;
		for (i = Number.Length - 2; i >= 0; --i) 
		{
			printf("%.8d", Number.Digits[i]);
		}
	}
}

LongNumber LongAdditionPrivate(LongNumber FirstNumber, LongNumber SecondNumber) 
{
	int NewSize;
	unsigned int CurrentBuffer = 0;
		
	if (FirstNumber.Length > SecondNumber.Length)
		NewSize = FirstNumber.Length;
	else
		NewSize = SecondNumber.Length;
	
	LongNumber Result = createNewLongNumber(NewSize + 1);
	int i;
	for (i = 0; i < Result.Length; ++i) 
	{
		if (i < FirstNumber.Length)
			CurrentBuffer += FirstNumber.Digits[i];
		if (i < SecondNumber.Length)
			CurrentBuffer += SecondNumber.Digits[i];
		lldiv_t FinResult = lldiv(CurrentBuffer, 100000000);
		Result.Digits[i] = FinResult.rem; 
		CurrentBuffer = FinResult.quot; 
	}
	
	if (FirstNumber.Sign)
		Result.Sign = !Result.Sign;

	if (Result.Digits[Result.Length - 1] == 0)
		Result.Length--;
	
	return Result;
}

LongNumber LongSubtractionPrivate(LongNumber FirstNumber, LongNumber SecondNumber) 
{
	int NewSize;
	long long CurrentBuffer = 0;
		
	if (FirstNumber.Length > SecondNumber.Length)
		NewSize = FirstNumber.Length;
	else
		NewSize = SecondNumber.Length;
	
	LongNumber Result = createNewLongNumber(NewSize);
	int i;
	for (i = 0; i < Result.Length; ++i) 
	{
		CurrentBuffer = (long long)FirstNumber.Digits[i] + Result.Digits[i];
		if (i < SecondNumber.Length) 
		{
			if (CurrentBuffer < SecondNumber.Digits[i]) 
			{
				CurrentBuffer += 100000000;
				Result.Digits[i + 1] = -1;
			}
			CurrentBuffer -= SecondNumber.Digits[i];
		}
		Result.Digits[i] = CurrentBuffer;
	}
	
	if (FirstNumber.Sign)
		Result.Sign = !Result.Sign;
		
	Result = removingLeadNulls(Result);	
	return Result;
}

LongNumber LongAddition(LongNumber FirstNumber, LongNumber SecondNumber) 
{
        if (!FirstNumber.Sign && SecondNumber.Sign) 
        {
		return LongSubtractionPrivate(FirstNumber, SecondNumber);                
        }
	if (FirstNumber.Sign && !SecondNumber.Sign) 
        {
		return LongSubtractionPrivate(SecondNumber, FirstNumber);                
        }
return LongAdditionPrivate(FirstNumber, SecondNumber);
}


LongNumber LongSubtraction(LongNumber FirstNumber, LongNumber SecondNumber) 
{
	if (FirstNumber.Sign && !SecondNumber.Sign) 
	{
		SecondNumber.Sign = !SecondNumber.Sign;
		return LongAdditionPrivate(FirstNumber, SecondNumber);
	}
	else if (!FirstNumber.Sign && SecondNumber.Sign) 
	{
		SecondNumber.Sign = !SecondNumber.Sign;
		return LongAdditionPrivate(FirstNumber, SecondNumber);
	}
	else
		return LongSubtractionPrivate(FirstNumber, SecondNumber);
}

void SubtractForDividing(LongNumber *FirstNumber, LongNumber SecondNumber) 
{
	int i;
	for (i = 0; i < FirstNumber->Length; ++i) 
	{
		long long CurrentBuffer = FirstNumber->Digits[i];

		if (i < SecondNumber.Length) 
		{
			if (CurrentBuffer < SecondNumber.Digits[i]) 
			{
				CurrentBuffer += 100000000;
				FirstNumber->Digits[i + 1]--;
			}
			CurrentBuffer = CurrentBuffer - SecondNumber.Digits[i];
		}
		FirstNumber->Digits[i] = CurrentBuffer;
	}	

	*FirstNumber = removingLeadNulls(*FirstNumber);
}

LongNumber LongMultiplying(LongNumber FirstNumber, LongNumber SecondNumber) 
{
	unsigned long long CurrentBuffer = 0, Multiple;
	LongNumber Result = createNewLongNumber(FirstNumber.Length + SecondNumber.Length);
	
	if (FirstNumber.Sign != SecondNumber.Sign)
		Result.Sign = 1;
	
	int i, j;
	for (i = 0; i < FirstNumber.Length; ++i) 
	{
		for (j = 0; j < SecondNumber.Length || CurrentBuffer; ++j) 
		{
			Multiple = FirstNumber.Digits[i];
			if (j < SecondNumber.Length)
				Multiple *= SecondNumber.Digits[j];
			else
				Multiple = 0;
			CurrentBuffer += Multiple + Result.Digits[i + j];
			lldiv_t FinResult = lldiv(CurrentBuffer, 100000000);
			Result.Digits[i + j] = FinResult.rem;
			CurrentBuffer = FinResult.quot; 
		}
	}
	return removingLeadNulls(Result);	
}

LongNumber LongDividing(LongNumber FirstNumber, LongNumber SecondNumber)
{
	LongNumber Result;
	
	if (FirstNumber.Length < SecondNumber.Length) 
	{
		Result = createNewLongNumber(1);
		Result.Digits[0] = 0;
		return Result;
	}

	if (SecondNumber.Length == 0) 
	{
		printf("Error: dividing by zero.");
		exit(1);
	}
	
	Result = createNewLongNumber(FirstNumber.Length - SecondNumber.Length + 1);

	if (FirstNumber.Sign != SecondNumber.Sign)
		Result.Sign = 1;
	
	int LeadNulls = 1; 
	
	LongNumber SecondNumberSubproduct, mSubproduct = createNewLongNumber(1), Part = createNewLongNumber(SecondNumber.Length + 1); 
	unsigned int l = 0, r = 100000000, m, x = 0;
	Part.Length = 0;
	int pos;
	for (pos = FirstNumber.Length - 1; pos >= 0; --pos) 
	{
		Part.Length++;
		int w;
		for (w = Part.Length - 1; w >= 1; --w) 
		{
			Part.Digits[w] = Part.Digits[w - 1];
		}
		Part.Digits[0] = FirstNumber.Digits[pos];
		
		while (l <= r) 
		{
			int k;
			m = (l + r) >> 1;
			mSubproduct.Digits[0] = m;
			SecondNumberSubproduct = LongMultiplying(SecondNumber, mSubproduct);
			if (SecondNumberSubproduct.Length == Part.Length)
			{
				for (k = SecondNumberSubproduct.Length - 1; k >= 0; --k) 
					if (SecondNumberSubproduct.Digits[k] < Part.Digits[k])
					{
						k = -1;
						break;
					}
			}
			if ((SecondNumberSubproduct.Length <= Part.Length)||(k == -1)||(k == 0)) 
			{
				x = m;
				l = m + 1;
			} 
			else 
			{
				r = m - 1;
			}
			deleteLongNumber(SecondNumberSubproduct);
		}
		
		mSubproduct.Digits[0] = x;
		SecondNumberSubproduct = LongMultiplying(SecondNumber, mSubproduct);
		SubtractForDividing(&Part, SecondNumberSubproduct);
		deleteLongNumber(SecondNumberSubproduct);

		if (x > 0 && LeadNulls) {
			LeadNulls = 0;
			Result.Length = pos + 1;
		}

		if (!LeadNulls)
			Result.Digits[pos] = x;
	}
	deleteLongNumber(Part);
	return Result;
}

LongNumber LongModule(LongNumber FirstNumber, LongNumber SecondNumber) 
{
	if (!FirstNumber.Sign && !SecondNumber.Sign) 
		if (FirstNumber.Length < FirstNumber.Length)
			return FirstNumber;

	if (SecondNumber.Length == 0) 
	{
		printf("Second number must exist and not be an equal zero.");
		exit(1);
	}

	LongNumber SecondNumberSubproduct, mSubproduct = createNewLongNumber(1), Part = createNewLongNumber(SecondNumber.Length + 1); 
	Part.Length = 0;
	unsigned int l = 0, r = 100000000, x = 0, m;
	int pos;
	for (pos = FirstNumber.Length - 1; pos >= 0; --pos) 
	{
		Part.Length++;
		int w;
		for (w = Part.Length - 1; w >= 1; --w) 
		{
			Part.Digits[w] = Part.Digits[w - 1];
		}
		Part.Digits[0] = FirstNumber.Digits[pos];
		
		while (l <= r) 
		{			
			m = (l + r) >> 1;
			int k;
			mSubproduct.Digits[0] = m;
			SecondNumberSubproduct = LongMultiplying(SecondNumber, mSubproduct);
			if (SecondNumberSubproduct.Length == Part.Length)
			{
				for (k = SecondNumberSubproduct.Length - 1; k >= 0; --k) 
					if (SecondNumberSubproduct.Digits[k] < Part.Digits[k])
					{
						k = -1;
						break;
					}
				if (k == 0)
					k = -1;
			}
			if ((SecondNumberSubproduct.Length <= Part.Length)||(k == -1)) 
			{
				x = m;
				l = m + 1;
			} 
			else 
			{
				r = m - 1;
			}
			deleteLongNumber(SecondNumberSubproduct);
			
		}
		mSubproduct.Digits[0] = x;
		SecondNumberSubproduct = LongMultiplying(SecondNumber, mSubproduct);
		SubtractForDividing(&Part, SecondNumberSubproduct);
		deleteLongNumber(SecondNumberSubproduct);
	}
	Part = removingLeadNulls(Part);

	if (Part.Length != 0 && (FirstNumber.Sign != SecondNumber.Sign)) 
		Part = LongSubtractionPrivate(SecondNumber, Part);

	Part.Sign = SecondNumber.Sign;
	return Part;
}

LongNumber LongModulePow(LongNumber FirstNumber, LongNumber SecondNumber, LongNumber Module) 
{
	if (SecondNumber.Sign) 
	{
		printf("Second number nust exist and be bigger than zero or equal by zero");
		exit(1);
	}

	LongNumber Result = createNewLongNumber(1);
	Result.Digits[0] = 1;
	
	if (SecondNumber.Length == 0) 
	{
		return Result;
	}
	
	LongNumber CurrentBuffer = CopyLongNumber(FirstNumber), State = CopyLongNumber(SecondNumber), Old, 
	One = createNewLongNumber(1), Two = createNewLongNumber(1);
	One.Digits[0] = 1;
	Two.Digits[0] = 2;
	
	while (State.Length != 0) 
	{
		if ((State.Digits[State.Length - 1] % 2) != 0) 
		{
			SubtractForDividing(&State, One);
			Old = Result;
			Result = LongMultiplying(Result, CurrentBuffer);
			deleteLongNumber(Old);
			if (Module.Digits != NULL) 
			{
				Old = Result;
				Result = LongModule(Result, Module);
				deleteLongNumber(Old);
			}
		}
		else 
		{
			Old = CurrentBuffer;
			CurrentBuffer = LongMultiplying(CurrentBuffer, CurrentBuffer);
			deleteLongNumber(Old);
			if (Module.Digits != NULL) 
			{
				Old = CurrentBuffer;
				Result = LongModule(CurrentBuffer, Module);
				deleteLongNumber(Old);
			}
			Old = State;
			State = LongDividing(State, Two);
			deleteLongNumber(Old);
		}
	}
	deleteLongNumber(One);
	deleteLongNumber(State);
	deleteLongNumber(CurrentBuffer);
	deleteLongNumber(Two);
	return Result;
}

int parity (LongNumber FirstNumber, LongNumber SecondNumber)
{
	int i = 0;
	if (FirstNumber.Length == SecondNumber.Length)	
		for (i = FirstNumber.Length - 1; i >= 0; --i)
			if (FirstNumber.Digits[i] == SecondNumber.Digits[i])
				return 1;
	return 0;
}

int more (LongNumber FirstNumber, LongNumber SecondNumber)
{
	int i = 0;
	if (FirstNumber.Length > SecondNumber.Length)
		return 1;
	if (FirstNumber.Length == SecondNumber.Length)	
		for (i = FirstNumber.Length - 1; i >= 0; --i)
		{
			if (FirstNumber.Digits[i] > SecondNumber.Digits[i])
				return 1;
			if (FirstNumber.Digits[i] <= SecondNumber.Digits[i])
				return 0;
		}
	return 0;
}
