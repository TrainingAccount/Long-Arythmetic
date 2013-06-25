#include <stdio.h>
#include "longnumber.h"

int main ()
{
	int workCycle = 13;
	LongNumber first, second, result, module;
	char selector;
	printf ("This is a calculator. \nFirst number must be putting in First.txt, \nsecond - in Second.txt; if you want to use a module,\nyou can use Module.txt");
	while (workCycle == 13)
	{
		printf("Please enter a command from list (+, -, *, /, ^, %): ");
		scanf ("%c", selector);
		switch (selector)
		{
			case '+':
				first = readingLongNumberFromFile("First.txt");
				second = readingLongNumberFromFile("Second.txt");
				result = LongAddition(first, second);
				writingLongNumberToFile ("Result.txt", result);
				deleteLongNumber(first);
				deleteLongNumber(second);
				deleteLongNumber(result);
				break;
			case '-':
				first = readingLongNumberFromFile("First.txt");
				second = readingLongNumberFromFile("Second.txt");
				result = LongSubtraction(first, second);
				writingLongNumberToFile ("Result.txt", result);
				deleteLongNumber(first);
				deleteLongNumber(second);
				deleteLongNumber(result);
				break;
			case '*':
				first = readingLongNumberFromFile("First.txt");
				second = readingLongNumberFromFile("Second.txt");
				result = LongMultiplying(first, second);
				writingLongNumberToFile ("Result.txt", result);
				deleteLongNumber(first);
				deleteLongNumber(second);
				deleteLongNumber(result);
				break;
			case '/':
				first = readingLongNumberFromFile("First.txt");
				second = readingLongNumberFromFile("Second.txt");
				result = LongDividing(first, second);
				writingLongNumberToFile ("Result.txt", result); 
				deleteLongNumber(first);
				deleteLongNumber(second);
				deleteLongNumber(result);
				break;
			case '^':
				first = readingLongNumberFromFile("First.txt");
				second = readingLongNumberFromFile("Second.txt");
				module = readingLongNumberFromFile("Module.txt");
				result = LongModulePow(first, second, module);
				writingLongNumberToFile ("Result.txt", result);
				deleteLongNumber(first);
				deleteLongNumber(second);
				deleteLongNumber(module);
				deleteLongNumber(result);
				break;
			case '%':
				first = readingLongNumberFromFile("First.txt");
				second = readingLongNumberFromFile("Second.txt");
				result = LongModule(first, second);
				writingLongNumberToFile ("Result.txt", result);
				deleteLongNumber(first);
				deleteLongNumber(second);
				deleteLongNumber(result);
				break;
		}
		
		module = readingLongNumberFromFile("Module.txt");
		if ((module.digits) && (selector != '^'))
		{
			LongNumber old = result;
			result = LongModule(result, module);
			deleteLongNumber(old);
		}
		deleteLongNumber(module);
		
	printf("If you wish to repeat this program press Enter; \nall other keys are ending program\n")
	scanf("%c", workCycle);
	}
return 0;	
}