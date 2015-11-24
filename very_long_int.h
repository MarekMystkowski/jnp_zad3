#ifndef VERY_LONG_INT_H
#define VERY_LONG_INT_H
#include <iostream>
#include <string>
#include <vector>

class VeryLongInt{
	private:
		bool isNaN;
		std::vector<uint32_t> data;
		int date;
	public:
		VeryLongInt();
		VeryLongInt(const VeryLongInt &);
		VeryLongInt(int);
		VeryLongInt(long long int);
		explicit VeryLongInt(const std::string &);
		explicit VeryLongInt(const char *);
		explicit operator bool() const;
		
		
		unsigned int numberOfBinaryDigits();
		bool isValid()const;
		
		VeryLongInt &operator=(const VeryLongInt &);
		VeryLongInt &operator+=(const VeryLongInt &);
		VeryLongInt &operator-=(const VeryLongInt &);
		VeryLongInt &operator*=(const VeryLongInt &);
		VeryLongInt &operator/=(const VeryLongInt &);
		VeryLongInt &operator%=(const VeryLongInt &);
		VeryLongInt &operator<<=(unsigned int);
		VeryLongInt &operator>>=(unsigned int);
		
};

VeryLongInt &operator+(const VeryLongInt &, const VeryLongInt &);
VeryLongInt &operator-(const VeryLongInt &, const VeryLongInt &);
VeryLongInt &operator*(const VeryLongInt &, const VeryLongInt &);
VeryLongInt &operator/(const VeryLongInt &, const VeryLongInt &);
VeryLongInt &operator%(const VeryLongInt &, const VeryLongInt &);
VeryLongInt &operator<<(const VeryLongInt &, unsigned int);
VeryLongInt &operator>>(const VeryLongInt &, unsigned int);

bool operator==(const VeryLongInt &, const VeryLongInt &);
bool operator!=(const VeryLongInt &, const VeryLongInt &);
bool operator<(const VeryLongInt &, const VeryLongInt &);
bool operator<=(const VeryLongInt &, const VeryLongInt &);
bool operator>(const VeryLongInt &, const VeryLongInt &);
bool operator>=(const VeryLongInt &, const VeryLongInt &);

//VeryLongInt const &Zero();
//VeryLongInt const &NaN();

#endif
