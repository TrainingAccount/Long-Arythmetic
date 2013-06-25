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
void writingLongNumberToFile(const char *, LongNumber);

LongNumber LongAdditionPrivate(LongNumber, LongNumber);
LongNumber LongAddition(LongNumber, LongNumber);

LongNumber LongSubtractionPrivate(LongNumber, LongNumber);
LongNumber LongSubtraction(LongNumber, LongNumber);
void SubtractForDividing(LongNumber*, LongNumber);

LongNumber LongMultiplying(LongNumber, LongNumber);

LongNumber LongDividing(LongNumber, LongNumber);

LongNumber LongModulePow(LongNumber, LongNumber, LongNumber);

LongNumber LongModule(LongNumber, LongNumber);

