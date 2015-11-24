#include <iostream>

class VeryLongInt{
	private:
		long long date;
	public:
		VeryLongInt();
		VeryLongInt(VeryLongInt const &);
		VeryLongInt(int);
		VeryLongInt(long long int);
		///*explicit */operator bool() const;
		
		
		//unsigned int numberOfBinaryDigits();
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

