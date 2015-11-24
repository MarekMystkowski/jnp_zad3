#include "very_long_int.h"
using namespace std;
VeryLongInt::VeryLongInt(){
	date = 0;
}
VeryLongInt::VeryLongInt(VeryLongInt const &x){
	date = x.date;
}
VeryLongInt::VeryLongInt(int x){
	date = x;
}
VeryLongInt::VeryLongInt(long long int x){
	date = (unsigned int) x;
}
bool VeryLongInt::isValid()const{
	return (this->date >= 0);
}
///*explicit */VeryLongInt::operator bool() const{
	//if(this->date == 0)return false;
	//return true;
//}
VeryLongInt & VeryLongInt::operator=(const VeryLongInt &x){
	this->date = x.date;
	return *this;
}
VeryLongInt & VeryLongInt::operator+=(const VeryLongInt &x){
	this->date += x.date;
	return *this;
}
VeryLongInt & VeryLongInt::operator-=(const VeryLongInt &x){
	this->date -= x.date;
	return *this;
}
VeryLongInt & VeryLongInt::operator*=(const VeryLongInt &x){
	this->date *= x.date;
	return *this;
}
VeryLongInt & VeryLongInt::operator/=(const VeryLongInt &x){
	this->date /= x.date;
	return *this;
}
VeryLongInt & VeryLongInt::operator%=(const VeryLongInt &x){
	this->date %= x.date;
	return *this;
}
VeryLongInt & VeryLongInt::operator<<=(unsigned int x){
	this->date <<= x;
	return *this;
}
VeryLongInt & VeryLongInt::operator>>=(unsigned int x){
	this->date >>= x;
	return *this;
}

VeryLongInt &operator+(const VeryLongInt &a, const VeryLongInt &b){
	VeryLongInt * result;
	result = new VeryLongInt(a);
	*result += b;
	return *result;
}
VeryLongInt &operator-(const VeryLongInt &a, const VeryLongInt &b){
	VeryLongInt * result;
	result = new VeryLongInt(a);
	*result -= b;
	return *result;
}
VeryLongInt &operator*(const VeryLongInt &a, const VeryLongInt &b){
	VeryLongInt * result;
	result = new VeryLongInt(a);
	*result *= b;
	return *result;
}
VeryLongInt &operator/(const VeryLongInt &a, const VeryLongInt &b){
	VeryLongInt * result;
	result = new VeryLongInt(a);
	*result /= b;
	return *result;
}
VeryLongInt &operator%(const VeryLongInt &a, const VeryLongInt &b){
	VeryLongInt * result;
	result = new VeryLongInt(a);
	*result %= b;
	return *result;
}
VeryLongInt &operator<<(const VeryLongInt &a, unsigned int b){
	VeryLongInt * result;
	result = new VeryLongInt(a);
	*result <<= b;
	return *result;
}
VeryLongInt &operator>>(const VeryLongInt &a, unsigned int b){
	VeryLongInt * result;
	result = new VeryLongInt(a);
	*result >>= b;
	return *result;
}

bool operator==(const VeryLongInt &a, const VeryLongInt &b){
	if(not (a.isValid() && b.isValid()) ) return false;
	return ((a - b).isValid() && (b - a).isValid());
}
bool operator!=(const VeryLongInt &a, const VeryLongInt &b){
	if(not (a.isValid() && b.isValid()) ) return false;
	return not (a == b);
}
bool operator<(const VeryLongInt &a, const VeryLongInt &b){
	if(not (a.isValid() && b.isValid()) ) return false;
	return ((b - a).isValid() && not (a - b).isValid());
}
bool operator<=(const VeryLongInt &a, const VeryLongInt &b){
	if(not (a.isValid() && b.isValid()) ) return false;
	return (b - a).isValid();
}
bool operator>(const VeryLongInt &a, const VeryLongInt &b){
	if(not (a.isValid() && b.isValid()) ) return false;
	return not (a <= b);
}
bool operator>=(const VeryLongInt &a, const VeryLongInt &b){
	if(not (a.isValid() && b.isValid()) ) return false;
	return not (a < b);
}
