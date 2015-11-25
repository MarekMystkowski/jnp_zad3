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
		void correct_invariants();
    void multiplyByDigitAndShift(VeryLongInt &, uint32_t, uint32_t) const;
	public:
		VeryLongInt(const VeryLongInt &);
		VeryLongInt(int arg = 0);
		VeryLongInt(long long int);
		explicit VeryLongInt(const std::string &);
		explicit VeryLongInt(const char *);
		explicit operator bool() const;
		
		
		size_t numberOfBinaryDigits();
		bool isValid()const;
		
		VeryLongInt &operator=(const VeryLongInt &);
		VeryLongInt &operator+=(const VeryLongInt &);
		VeryLongInt &operator-=(const VeryLongInt &);
		VeryLongInt &operator*=(const VeryLongInt &);
		VeryLongInt &operator/=(const VeryLongInt &);
		VeryLongInt &operator%=(const VeryLongInt &);
		VeryLongInt &operator<<=(unsigned int);
		VeryLongInt &operator>>=(unsigned int);
		friend std::ostream & operator<<(std::ostream &, const VeryLongInt &);
		
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

VeryLongInt const &Zero();
VeryLongInt const &NaN();

#endif
