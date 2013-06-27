extern "C" 
{
#include "longnumber.h"
};

class LongNum 
{
public:
	LongNum();
	LongNum(const char *);
	~LongNum();
	LongNum(const LongNum &);
	LongNum &operator =(const LongNum &); 
	const LongNum operator +(LongNum &);
	const LongNum operator -(LongNum &);
	const LongNum operator *(LongNum &);
	const LongNum operator /(LongNum &);
	const LongNum operator %(LongNum &);
	const LongNum operator ^(LongNum &);
	LongNum(const LongNumber &);
	const LongNumber& getNumber() const;
	void toFile(const char *);
	int operator ==(const LongNum &);
	int operator >(const LongNum &);
private:
	LongNumber Number;
};
