/* Do zmiany jest : // XXXXXXXXXXXXXXXXXXXXXXXXXXXX
 * pozostałę funkcje/metody powinny pozostać bez zmian.
 */


#include "very_long_int.h"
using namespace std;
VeryLongInt::VeryLongInt(){
	*this = VeryLongInt(0);
}
VeryLongInt::VeryLongInt(const VeryLongInt &x){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	date = x.date;
}
VeryLongInt::VeryLongInt(int x){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	date = x;
}
VeryLongInt::VeryLongInt(long long int x){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	date = (int) x;
}
VeryLongInt::VeryLongInt(const string &x){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	date = 42;
}
VeryLongInt::VeryLongInt(const char *x){
	*this = VeryLongInt(string(x));
}
bool VeryLongInt::isValid()const{
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	return (this->date >= 0);
}

VeryLongInt::operator bool() const{
	if(not isValid()) return false;
	if(*this == 0)return false;
	return true;
}
unsigned int VeryLongInt::numberOfBinaryDigits(){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	if(this-> date == 0) return 0;
	return 1;
}
VeryLongInt & VeryLongInt::operator=(const VeryLongInt &x){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	this->date = x.date;
	return *this;
}
VeryLongInt & VeryLongInt::operator+=(const VeryLongInt &x){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	this->date += x.date;
	return *this;
}
VeryLongInt & VeryLongInt::operator-=(const VeryLongInt &x){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	this->date -= x.date;
	return *this;
}
VeryLongInt & VeryLongInt::operator*=(const VeryLongInt &x){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	this->date *= x.date;
	return *this;
}
VeryLongInt & VeryLongInt::operator/=(const VeryLongInt &x){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	this->date /= x.date;
	return *this;
}
VeryLongInt & VeryLongInt::operator%=(const VeryLongInt &x){
	VeryLongInt k = *this / x;
	*this -= k * x;
	return *this;
}
VeryLongInt & VeryLongInt::operator<<=(unsigned int x){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	this->date <<= x;
	return *this;
}
VeryLongInt & VeryLongInt::operator>>=(unsigned int x){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
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
