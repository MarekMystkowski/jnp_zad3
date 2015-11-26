#ifndef VERY_LONG_INT_H
#define VERY_LONG_INT_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

class VeryLongInt{
  private:
    bool isNaN;
    std::vector<uint32_t> data;
    int date;
    void correct_invariants();
    void multiplyByDigitAndShift(VeryLongInt &, uint32_t, uint32_t) const;
    
  public:
    VeryLongInt(const VeryLongInt &);
    VeryLongInt(uint32_t arg = 0U);
    VeryLongInt(uint64_t);
    VeryLongInt(int32_t x){
      *this = VeryLongInt((uint32_t) x);
    }
    
    VeryLongInt(int64_t x){
      *this = VeryLongInt((uint64_t) x);
    }

    VeryLongInt(unsigned long long x){
      *this = VeryLongInt((uint64_t) x);
    }
    
    VeryLongInt(long long x){
      *this = VeryLongInt((uint64_t) x);
    }
    
    VeryLongInt(char) = delete;
    VeryLongInt(char16_t) = delete;
    VeryLongInt(char32_t) = delete;
    VeryLongInt(wchar_t) = delete;
    VeryLongInt(bool) = delete;
    explicit VeryLongInt(const std::string &);
    explicit VeryLongInt(const char *);
    
    explicit operator bool() const;
    
    size_t numberOfBinaryDigits()const;
    bool isValid()const;
    
    VeryLongInt &operator=(const VeryLongInt &);
    VeryLongInt &operator+=(const VeryLongInt &);
    VeryLongInt &operator-=(const VeryLongInt &);
    VeryLongInt &operator*=(const VeryLongInt &);
    VeryLongInt &operator/=(const VeryLongInt &);
    VeryLongInt &operator%=(const VeryLongInt &);
    VeryLongInt &operator<<=(uint64_t);
    VeryLongInt &operator<<=(uint32_t x){
      *this <<= (uint64_t) x;
      return *this;
    }
    
    VeryLongInt &operator<<=(int32_t x){
      *this <<= (uint64_t) x;
      return *this;
    }
    
    VeryLongInt &operator<<=(int64_t x){
      *this <<= (uint64_t) x;
      return *this;
    }
    
    VeryLongInt &operator<<=(unsigned long long  x){
      *this <<= (uint64_t) x;
      return *this;
    }
    
    VeryLongInt &operator<<=(long long x){
      *this <<= (uint64_t) x;
      return *this;
    }
    
    VeryLongInt &operator>>=(uint64_t);
    VeryLongInt &operator>>=(uint32_t x){
      *this >>= (uint64_t) x;
      return *this;
    }
    
    VeryLongInt &operator>>=(int32_t x){
      *this >>= (uint64_t) x;
      return *this;
    }
    
    VeryLongInt &operator>>=(int64_t x){
      *this >>= (uint64_t) x;
      return *this;
    }
    
    VeryLongInt &operator>>=(unsigned long long  x){
      *this >>= (uint64_t) x;
      return *this;
    }
    
    VeryLongInt &operator>>=(long long x){
      *this >>= (uint64_t) x;
      return *this;
    }
    
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
