#include <string>
#include "longnumber_cpp.h"
#include <cstdio>

LongNum::LongNum(const char* FileName) 
{
	Number = readingLongNumberFromFile(FileName);
}

LongNum::LongNum() 
{
	Number = createNewLongNumber(0);
}

LongNum::~LongNum() 
{
	if (Number.Digits)
		deleteLongNumber(Number);
}

LongNum::LongNum(const LongNumber &IntegralNumber) 
{
	Number = IntegralNumber;
}

LongNum::LongNum(const LongNum &IntegralNumber) 
{
	Number = CopyLongNumber(IntegralNumber.getNumber());
}

LongNum &LongNum::operator =(const LongNum &SecondPart) 
{
	if (this == &SecondPart)
		return *this;
	deleteLongNumber(Number);
	Number = CopyLongNumber(SecondPart.getNumber());
	return *this;
}

const LongNumber &LongNum::getNumber() const 
{
	return Number;
}

const LongNum LongNum::operator +(LongNum &SecondPart) 
{
	return LongNum(LongAddition(Number, SecondPart.getNumber()));
}

const LongNum LongNum::operator -(LongNum &SecondPart) 
{
	return LongNum(LongSubtraction(Number, SecondPart.getNumber()));
} 

const LongNum LongNum::operator *(LongNum &SecondPart) 
{
	return LongNum(LongMultiplying(Number, SecondPart.getNumber()));
}

const LongNum LongNum::operator /(LongNum &SecondPart) 
{
	return LongNum(LongDividing(Number, SecondPart.getNumber()));
}

const LongNum LongNum::operator %(LongNum &SecondPart) 
{
	return LongNum(LongModule(Number, SecondPart.getNumber()));
}

const LongNum LongNum::operator ^(LongNum &SecondPart) 
{
	LongNumber ThirdPart = createNewLongNumber(0);
	return LongNum(LongModulePow(Number, SecondPart.getNumber(), ThirdPart));
}

void LongNum::toFile(const char * FileName) 
{
	writingLongNumberToFile(FileName, Number);
}

int LongNum::operator ==(const LongNum &second)
{
	return (parity(Number, second.getNumber()));
}

int LongNum::operator >(const LongNum &second)
{
	return (more(Number, second.getNumber()));
}
