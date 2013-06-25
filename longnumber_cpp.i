%module longnumber_cpp

%{
#define SWIG_FILE_WITH_INIT
#include "longnumber_cpp.h"
%}

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
private:
	LongNumber Number;
};
