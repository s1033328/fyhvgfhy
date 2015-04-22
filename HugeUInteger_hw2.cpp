#include<iostream>
#include"HugeUInteger_hw2.h"
using namespace std;

ostream &operator<<(ostream &output, const HugeUInteger &in){
	for (int i = in._length - 1; i >= 0; i--)
		output << in.hugeinteger[i];
	cout << endl;
	return output;
}
HugeUInteger::HugeUInteger(){
	for (int i = 0; i < MAX; i++)
		hugeinteger[i] = 0;
	_length = 0;
}
HugeUInteger::HugeUInteger(HugeUInteger &in){
	_length = in._length;
	for (int i = 0; i < _length; i++)
		hugeinteger[i] = in.hugeinteger[i];

}
HugeUInteger HugeUInteger::random(unsigned int size){
	HugeUInteger num;
	num._length = size;
	for (int i = 0; i < MAX; i++)
		num.hugeinteger[i] = 0;
	for (int i = 0; i < size; i++){
		num.hugeinteger[i] = rand() % 10;
		if (i == size - 1)
			num.hugeinteger[i] = rand() % 9 + 1;
	}
	return num;
}
HugeUInteger HugeUInteger::zero(){
	HugeUInteger zero;
	zero._length = 1;
	zero.hugeinteger[0] = 0;
	return zero;
}
HugeUInteger HugeUInteger::operator=(const HugeUInteger &right){
	for (int i = 0; i < _length; i++)
		hugeinteger[i] = 0;
	_length = right._length;
	for (int i = 0; i < right._length; i++)
		hugeinteger[i] = right.hugeinteger[i];
	return *this;
}
bool HugeUInteger::operator==(const HugeUInteger &right){
	if (_length != right._length)
		return false;
	else{
		for (int i = 0; i < _length; i++){
			if (hugeinteger[i] != right.hugeinteger[i])
				return false;
		}
		return true;
	}
}
bool HugeUInteger::operator!=(const HugeUInteger &right){
	if (_length != right._length)
		return true;
	else{
		for (int i = 0; i < _length; i++){
			if (hugeinteger[i] != right.hugeinteger[i])
				return true;
		}
		return false;
	}
}
bool HugeUInteger::operator<(const HugeUInteger &right){
	if (_length < right._length)
		return true;
	else if (_length > right._length)
		return false;
	else{
		for (int i = _length - 1; i >= 0; i--){
			if (hugeinteger[i] > right.hugeinteger[i])
				return false;
			else if (hugeinteger[i] < right.hugeinteger[i])
				return true;
		}
		return false;
	}
}
bool HugeUInteger::operator>(const HugeUInteger &right){
	if (_length > right._length)
		return true;
	else if (_length < right._length)
		return false;
	else{
		for (int i = _length - 1; i >= 0; i--){
			if (hugeinteger[i] < right.hugeinteger[i])
				return false;
			else if (hugeinteger[i] > right.hugeinteger[i])
				return true;
		}
		return false;
	}
}
HugeUInteger HugeUInteger::operator+(const HugeUInteger &right){
	HugeUInteger sum;
	if (_length >= right._length)
		sum._length = _length + 1;
	else
		sum._length = right._length + 1;
	for (unsigned int i = 0; i < _length; i++)
		sum.hugeinteger[i] = hugeinteger[i];

	for (unsigned int i = 0; i < right._length; i++)
		sum.hugeinteger[i] += right.hugeinteger[i];
	for (int i = 0; i < sum._length; i++){
		if (sum.hugeinteger[i] >= 10){
			sum.hugeinteger[i] -= 10;
			sum.hugeinteger[i + 1]++;
		}
	}
	for (int i = sum._length - 1; i >= 0; i--){
		if (sum.hugeinteger[i] != 0){
			sum._length = i + 1;
			break;
		}
	}
	return sum;
}
HugeUInteger HugeUInteger::operator-(const HugeUInteger &right){
	HugeUInteger difference;
	if (_length < right._length){
		difference = zero();
		return difference;
	}
	else
	{
		difference._length = _length;
		for (int i = 0; i < _length; i++)
			difference.hugeinteger[i] = hugeinteger[i];
		for (int i = 0; i < right._length; i++)
			difference.hugeinteger[i] -= right.hugeinteger[i];
		for (int i = 0; i < difference._length; i++){
			if (difference.hugeinteger[i] < 0){
				difference.hugeinteger[i] += 10;
				difference.hugeinteger[i + 1]--;
			}
		}
		for (int i = difference._length - 1; i >= 0; i--)
		{
			if (difference.hugeinteger[i] != 0)
			{
				break;
			}
			else if (difference.hugeinteger[i] == 0)
			{
				difference._length--;
			}
		}
	}

	return difference;
}
HugeUInteger HugeUInteger::operator*(const HugeUInteger &right){

	int productSize = _length + right._length;

	HugeUInteger product;
	product._length = productSize;
	for (int i = 0; i<_length; i++)
	{
		for (int j = 0; j<right._length; j++)
		{
			product.hugeinteger[i + j] += hugeinteger[i] * right.hugeinteger[j];
			if (product.hugeinteger[i + j]>9)
			{
				product.hugeinteger[i + j + 1] += product.hugeinteger[i + j] / 10;
				product.hugeinteger[i + j] %= 10;
			}
		}
	}

	for (int i = productSize - 1; i > 0; i--)
	{
		if (product.hugeinteger[i] != 0)
		{
			break;
		}
		else if (product.hugeinteger[i] == 0)
		{
			product._length -= 1;
		}
	}

	return product;

}
HugeUInteger HugeUInteger::operator/(const HugeUInteger &right){
	HugeUInteger buffer, quotient, divisor;
	int size;
	divisor = right;
	buffer._length = _length;
	quotient._length = _length - divisor._length + 1;
	for (int i = 0; i < buffer._length; i++)
		buffer.hugeinteger[i] = 0;
	size = _length - divisor._length;
	for (int i = size; i < _length; i++)
		buffer.hugeinteger[i] = divisor.hugeinteger[i - size];
	if (buffer>*this&&buffer == *this)
		quotient._length--;
	for (int i = 0; i < quotient._length; i++)
		quotient.hugeinteger[i] = 0;
	for (int i = quotient._length - 1; i >= 0; i--){
		quotient.hugeinteger[i] = 10;

		do{
			quotient.hugeinteger[i]--;
			buffer = (quotient*divisor);
		} while (*this < buffer);
	}
	for (int i = quotient._length - 1; i >= 0; i--){
		if (quotient.hugeinteger[i] == 0){
			if (i == 0)
				break;
			quotient._length--;
		}
		else break;
	}

	return quotient;
}
HugeUInteger HugeUInteger::operator%(const HugeUInteger &right){
	HugeUInteger buffer, quotient, divisor, remainder, a;
	int size;
	divisor = right;
	buffer._length = _length;
	quotient._length = _length - divisor._length + 1;
	for (int i = 0; i < buffer._length; i++)
		buffer.hugeinteger[i] = 0;
	size = _length - divisor._length;
	for (int i = size; i < _length; i++)
		buffer.hugeinteger[i] = divisor.hugeinteger[i - size];
	if (buffer>*this&&buffer == *this)
		quotient._length--;
	for (int i = 0; i < quotient._length; i++)
		quotient.hugeinteger[i] = 0;
	for (int i = quotient._length - 1; i >= 0; i--){
		quotient.hugeinteger[i] = 10;

		do{
			quotient.hugeinteger[i]--;
			buffer = (quotient*divisor);
		} while (*this < buffer);
	}
	for (int i = quotient._length - 1; i >= 0; i--){
		if (quotient.hugeinteger[i] == 0){
			if (i == 0)
				break;
			quotient._length--;
		}
		else break;
	}
	remainder = (quotient*divisor);
	a = *this - remainder;


	return a;
}