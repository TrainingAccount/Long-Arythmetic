#include <cstdio>
#include "longnumber_cpp.h"

int main()
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
				result = first + second;
				writingLongNumberToFile ("Result.txt", result);
				deleteLongNumber(first);
				deleteLongNumber(second);
				deleteLongNumber(result);
				break;
			case '-':
				first = readingLongNumberFromFile("First.txt");
				second = readingLongNumberFromFile("Second.txt");
				result = first - second;
				writingLongNumberToFile ("Result.txt", result);
				deleteLongNumber(first);
				deleteLongNumber(second);
				deleteLongNumber(result);
				break;
			case '*':
				first = readingLongNumberFromFile("First.txt");
				second = readingLongNumberFromFile("Second.txt");
				result = first * second;
				writingLongNumberToFile ("Result.txt", result);
				deleteLongNumber(first);
				deleteLongNumber(second);
				deleteLongNumber(result);
				break;
			case '/':
				first = readingLongNumberFromFile("First.txt");
				second = readingLongNumberFromFile("Second.txt");
				result = first / second;
				writingLongNumberToFile ("Result.txt", result);
				deleteLongNumber(first);
				deleteLongNumber(second);
				deleteLongNumber(result);
				break;
			case '^':
				first = readingLongNumberFromFile("First.txt");
				second = readingLongNumberFromFile("Second.txt");
				result = first ^ second;
				writingLongNumberToFile ("Result.txt", result);
				deleteLongNumber(first);
				deleteLongNumber(second);
				deleteLongNumber(result);
				break;
			case '%':
				first = readingLongNumberFromFile("First.txt");
				second = readingLongNumberFromFile("Second.txt");
				result = first % second;
				writingLongNumberToFile ("Result.txt", result);
				deleteLongNumber(first);
				deleteLongNumber(second);
				deleteLongNumber(result);
				break;
		}
		
		module = readingLongNumberFromFile("Module.txt");
		if ((module.digits) && (selector != '^'))
		{
			result = result % module;
		}
		deleteLongNumber(module);
		
	printf("If you wish to repeat this program press Enter; \nall other keys are ending program\n")
	scanf("%c", workCycle);
	}
return 0:	
}