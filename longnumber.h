typedef struct BigNum {
	int *Digits;
	char Sign;
	int Length;
} LongNumber;

LongNumber createNewLongNumber(int);
LongNumber CopyLongNumber(LongNumber);
void deleteLongNumber(LongNumber);

LongNumber removeLeadNulls(LongNumber); 

LongNumber readingLongNumberFromFile(const char *);
LongNumber readingLongNumberFromString(const char *);
void writingLongNumberToFile(const char *, LongNumber);
void writingLongNumberToString(LongNumber);

LongNumber LongAdditionPrivate(LongNumber, LongNumber);
LongNumber LongAddition(LongNumber, LongNumber);

LongNumber LongSubtractionPrivate(LongNumber, LongNumber);
LongNumber LongSubtraction(LongNumber, LongNumber);
void SubtractForDividing(LongNumber*, LongNumber);

LongNumber LongMultiplying(LongNumber, LongNumber);

LongNumber LongDividing(LongNumber, LongNumber);

LongNumber LongModulePow(LongNumber, LongNumber, LongNumber);

LongNumber LongModule(LongNumber, LongNumber);

int parity(LongNumber, LongNumber);
int more(LongNumber, LongNumber);
