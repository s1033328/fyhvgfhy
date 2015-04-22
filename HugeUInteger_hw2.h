#ifndef HUGE_UINTEGER_H
#define HUGE_UINTEGER_H
#include <vector>
using namespace std;
#define MAX 1000 //< max length of huge interger
class HugeUInteger
{
	friend ostream &operator<<(ostream &output, const HugeUInteger &in);
public:
	HugeUInteger(); //< default constructor (the default value = 0)
	HugeUInteger(HugeUInteger &in); //< copy constructor
	static HugeUInteger random(unsigned int size); //< randomly generate an integer, 
	//< the highest digit should not be ZERO
	static HugeUInteger zero(); //< zero this number (size = 1)
	HugeUInteger operator=(const HugeUInteger &right); //< assignment
	bool operator==(const HugeUInteger &right); //< equal to
	bool operator!=(const HugeUInteger &right); //< not equal to
	bool operator<(const HugeUInteger &right);  //< less than
	bool operator>(const HugeUInteger &right);  //< greater than

	HugeUInteger operator+(const HugeUInteger &right);
	//< addition operator; HugeUInteger + HugeUInteger
	HugeUInteger  operator-(const HugeUInteger &right);
	//< subtraction operator; HugeUInteger  - HugeUInteger ;
	//< (Use ZERO to replace negative result)
	HugeUInteger  operator*(const HugeUInteger &right);
	//< multiplication operator; HugeUInteger  * HugeUInteger 
	HugeUInteger  operator/(const HugeUInteger &right);
	//< division operator; HugeUInteger  / HugeUInteger 
	HugeUInteger  operator%(const HugeUInteger &right);
	//< modulus operator; HugeUInteger  % HugeUInteger

private:
	int hugeinteger[MAX];
	int _length;
	///add something to stores a huge integer (dynamic array or std::vector or …)
	///add some helper functions
};

#endif