/* Do zmiany jest : // XXXXXXXXXXXXXXXXXXXXXXXXXXXX
 * pozostałę funkcje/metody powinny pozostać bez zmian.
 */
/* Założenia:
 * 1) przyjmujuemy też liczby ujemne do konstruktorów, wtedy żutujemy bitowo
 *    na liczby nieujemne.
 * 2) pilnujemy niezmienika że po każdej operacji:
 * 		-wektor data ma conajmniej jeden element.
 * 		-wektor data nie ma na końcu liczby == 0 (chyba że to jedyna wartość).
 */


#include "very_long_int.h"
using namespace std;
VeryLongInt::VeryLongInt(){
	*this = VeryLongInt(0);
}
VeryLongInt::VeryLongInt(const VeryLongInt &x){
	isNaN = x.isNaN;
	data = x.data;
}
VeryLongInt::VeryLongInt(int x){
	isNaN = false;
	data.clear();
	data.push_back(x);
}
VeryLongInt::VeryLongInt(long long int x){
	uint32_t tmp1;
	tmp1 = (uint32_t) (x % (1LL << 32));
	*this = VeryLongInt((int)tmp1);
	tmp1 = (uint32_t) (x >> 32);
	if(tmp1 > 0) data.push_back(tmp1);
}
VeryLongInt::VeryLongInt(const string &x){
// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	*this = VeryLongInt(42);
}
VeryLongInt::VeryLongInt(const char *x){
	*this = VeryLongInt(string(x));
}
bool VeryLongInt::isValid()const{
	return not isNaN;
}
void VeryLongInt::correct_invariants(){
	if(data.size() == 0) data.push_back(0);
	while(data[data.size() - 1] == 0 && data.size() > 1)
		data.pop_back();
}
VeryLongInt::operator bool() const{
	if(not isValid()) return false;
	if(*this == 0)return false;
	return true;
}
size_t VeryLongInt::numberOfBinaryDigits(){
	if(not isValid())return 0;
	size_t result = (data.size() - 1) * 32;
	uint32_t tmp = data[data.size() - 1];
	while(tmp > 0){
		tmp >>= 1;
		result++;
	}
	return result;
}
VeryLongInt & VeryLongInt::operator=(const VeryLongInt &x){
	this->isNaN = x.isNaN;
	this->data = x.data;
	return *this;
}
VeryLongInt & VeryLongInt::operator+=(const VeryLongInt &x){
	if(isNaN || x.isNaN)
		isNaN = true;
	else {
		uint64_t tmp = 0L;
		while(data.size() < x.data.size())
			data.push_back(0);
		
		for(size_t i = 0; i < x.data.size(); i++){
			tmp += x.data[i] +  data[i];
			data[i] = (uint32_t) (tmp % (1L << 32));
			tmp /= 1L << 32;
		}
		data.push_back((uint32_t) (tmp % (1L << 32)));
		correct_invariants();
	}
	return *this;
}
VeryLongInt & VeryLongInt::operator-=(const VeryLongInt &x){
	if(isNaN || x.isNaN || data.size() < x.data.size())
		isNaN = true;
	else {
		uint64_t tmp = 1L << 32;
		for(size_t i = 0; i < x.data.size(); i++){
			tmp = tmp - x.data[i] +  data[i];
			data[i] = (uint32_t) (tmp % (1L << 32));
			if(tmp < (1L << 32){
				//niedobór 
				
			}else {
				tmp = 1L << 32;
			}
		}
		if(tmp < (1L << 32){
				//niedobór 
				
			}
		correct_invariants();
	}
	return *this;
}
VeryLongInt & VeryLongInt::operator*=(const VeryLongInt &x){
	if(this->isNaN || x.isNaN)
		this->isNaN = true;
	else {
		// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
		this->data[0] *= x.data[0];
	}
	return *this;
}
VeryLongInt & VeryLongInt::operator/=(const VeryLongInt &x){
	if(this->isNaN || x.isNaN || x == 0)
		this->isNaN = true;
	else {
		// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
		this->data[0] /= x.data[0];
	}
	return *this;
}
VeryLongInt & VeryLongInt::operator%=(const VeryLongInt &x){
	VeryLongInt k = *this / x;
	*this -= k * x;
	return *this;
}
VeryLongInt & VeryLongInt::operator<<=(unsigned int x){
	if(this->isNaN)
		this->isNaN = true;
	else {
		// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
		this->data[0] <<= x;
	}
	return *this;
}
VeryLongInt & VeryLongInt::operator>>=(unsigned int x){
	if(this->isNaN)
		this->isNaN = true;
	else {
		// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
		this->data[0] >>= x;
	}
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
