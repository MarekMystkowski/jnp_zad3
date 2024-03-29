#include "very_long_int.h"
using namespace std;

static const uint64_t BASE = 1LL << 32;

VeryLongInt::VeryLongInt(const VeryLongInt &x) : isNaN(x.isNaN), data(x.data) {
}

VeryLongInt::VeryLongInt(uint32_t x): isNaN(false) {
  data.clear();
  data.push_back(x);
}

VeryLongInt::VeryLongInt(uint64_t x): isNaN(false) {
  data.clear();
  uint32_t tempNumber;
  tempNumber = (uint32_t) (x % BASE);
  data.push_back(tempNumber);
  tempNumber = (uint32_t) (x >> 32);
  if (tempNumber > 0) data.push_back(tempNumber);
}

VeryLongInt::VeryLongInt(const string &x) {
  VeryLongInt currentResult;
  for (char c : x) {
    currentResult = (currentResult * 10) + (int)(c - '0');
    if (c < '0' || c > '9') 
      currentResult.isNaN = true;
  }
  *this = currentResult;
}

VeryLongInt::VeryLongInt(const char *x) {
  *this = VeryLongInt(string(x));
}

bool VeryLongInt::isValid() const {
  return not isNaN;
}

void VeryLongInt::correct_invariants() {
  if (data.size() == 0)
    data.push_back(0);
  while (data[data.size() - 1] == 0 && data.size() > 1)
    data.pop_back();
}

VeryLongInt::operator bool() const {
  if (not isValid()) 
    return false;
  if (*this == 0)
    return false;
  return true;
}

size_t VeryLongInt::numberOfBinaryDigits() const {
  if (not isValid())
    return 0;
  if (*this == 0)
    return 1;
  size_t result = (data.size() - 1) * 32;
  uint32_t tmp = data[data.size() - 1];
  while (tmp > 0) {
    tmp >>= 1;
    result++;
  }
  return result;
}

VeryLongInt & VeryLongInt::operator=(const VeryLongInt &x) {
  isNaN = x.isNaN;
  data = x.data;
  return *this;
}

VeryLongInt & VeryLongInt::operator+=(const VeryLongInt &x) {
  if (isNaN || x.isNaN)
    isNaN = true;
  else {
    uint64_t tmp = 0L;
    while(data.size() < x.data.size())
      data.push_back(0);
    data.push_back(0);
    
    for (size_t i = 0; i < x.data.size(); i++) {
      tmp += (uint64_t) x.data[i] + (uint64_t) data[i];
      data[i] = (uint32_t) (tmp % BASE);
      tmp /= BASE;
    }
    for (size_t i = x.data.size(); tmp > 0L; i++) {
      tmp += data[i];
      data[i] = (uint32_t) (tmp % BASE);
      tmp /= BASE;
    }
    correct_invariants();
  }
  return *this;
}

VeryLongInt & VeryLongInt::operator-=(const VeryLongInt &x) {
  if (isNaN || x.isNaN || data.size() < x.data.size())
    isNaN = true;
  else {
    uint64_t tmp = BASE;
    for (size_t i = 0; i < x.data.size(); i++) {
      tmp +=  (uint64_t) data[i] - (uint64_t) x.data[i];
      data[i] = (uint32_t) (tmp % BASE);
      if (tmp < BASE) {
        tmp = BASE - 1L;
      } else {
        tmp = BASE;
      }
    }
    if (tmp < BASE) {
      if (data.size() > x.data.size()) {
        data[x.data.size()] -= 1;
      } else {
        isNaN = true;
      }
    }
    correct_invariants();
  }
  return *this;
}

void VeryLongInt::multiplyByDigitAndShift(
    VeryLongInt &result,
    uint32_t digitArg,
    uint32_t shift) const {
  result.data = vector <uint32_t>();
  uint64_t currentTempResult = 0;
  uint32_t currentRest = 0;
  uint32_t sizeOfThisData = data.size();
  for (uint32_t i = 0; i < shift; ++i)
    result.data.push_back(0);
  for (uint32_t i = 0; i < sizeOfThisData; ++i) {
    currentTempResult = (uint64_t)digitArg * (uint64_t)data[i] + (uint64_t)currentRest;
    result.data.push_back(currentTempResult % BASE);
    currentRest = currentTempResult / BASE;
  }
  if (currentRest > 0) 
    result.data.push_back(currentRest);
}

VeryLongInt & VeryLongInt::operator*= (const VeryLongInt &x) {
  if (isNaN || x.isNaN)
    isNaN = true;
  else {
    VeryLongInt currentResult;
    VeryLongInt currentTemp ;
    for (size_t i = 0; i < data.size(); ++i) {
      x.multiplyByDigitAndShift(
          currentTemp,
          data[i],
          i);
      currentResult += currentTemp;
    }
    *this = currentResult;
  }
  correct_invariants();
  return *this;
}

VeryLongInt & VeryLongInt::operator/=(const VeryLongInt &x) {
  if (isNaN || x.isNaN || x == 0)
    isNaN = true;
  else {
    const uint32_t lengthOfX = x.data.size();
    const uint32_t lengthOfThis = data.size();
    VeryLongInt result;
    if (lengthOfThis < lengthOfX) 
      *this = result;
    else {
      VeryLongInt helperNumberDividing(x);
      VeryLongInt helperNumberDivided(*this);
      int32_t nrOfZerosAddedToHelper = lengthOfThis - lengthOfX;
      if (nrOfZerosAddedToHelper > 0) {
        vector <uint32_t> zerosToInsert(nrOfZerosAddedToHelper, 0);
        helperNumberDividing.data.insert(
            helperNumberDividing.data.begin(),
            zerosToInsert.begin(),
            zerosToInsert.end());
      }
      while (nrOfZerosAddedToHelper >= 0) {
        uint64_t base2Counter = 1;
        int32_t base2Index = 0;
        vector <VeryLongInt> base2Vector;
        VeryLongInt temp;
        base2Vector.push_back(helperNumberDividing);
        while ((temp = base2Vector[base2Index] * 2) <= helperNumberDivided) {
          base2Counter *= 2;
          base2Index += 1;
          base2Vector.push_back(temp);
        }
        while (base2Index >= 0) {
          while (base2Vector[base2Index] <= helperNumberDivided) {
            helperNumberDivided -= base2Vector[base2Index];
            result += base2Counter;
          }
          base2Counter /= 2;
          base2Index -= 1;
        }
        --nrOfZerosAddedToHelper;
        helperNumberDividing.data.erase(
            helperNumberDividing.data.begin());
        if (result > 0 && nrOfZerosAddedToHelper >= 0) 
          result.data.insert(
              result.data.begin(),
              0);
      }
      *this = result;
    }
  }
  correct_invariants();
  return *this;
}

VeryLongInt & VeryLongInt::operator%=(const VeryLongInt &x) {
  if (isNaN || x.isNaN || x == 0) {
    isNaN = true;
  } else {
  VeryLongInt k = (*this / x);
  *this -= k * x;
  }
  return *this;
}

VeryLongInt & VeryLongInt::operator<<=(uint64_t x) {
  if (not isNaN) {
    uint64_t temp = x / 32;
    if (temp > 0) {
    vector<uint32_t> helperVector = data;
    size_t index = 0;
    while (index < temp) {
      data.push_back(0);
      data[index++] = 0;
    }
    for (uint32_t var : helperVector)
      data[index++] = var;
  }
  temp = x - temp * 32;
  
    *this = *this * (1 << temp);
  }
  return *this;
}
VeryLongInt & VeryLongInt::operator>>=(uint64_t x) {
   if (not isNaN) {
    uint64_t temp = x / 32;
    if (temp > 0) {
    for (size_t index= 0; index + temp  < data.size() ; index++)
      data[index] = data[index + temp];
    for (size_t index= 0; index < temp ; index++)
      data.pop_back();
  }
  temp = x - temp * 32;
  
    *this = *this / (1 << temp);
  }
  return *this;
}

VeryLongInt &operator+(const VeryLongInt &a, const VeryLongInt &b) {
  VeryLongInt * result;
  result = new VeryLongInt(a);
  *result += b;
  return *result;
}

VeryLongInt &operator-(const VeryLongInt &a, const VeryLongInt &b) {
  VeryLongInt * result;
  result = new VeryLongInt(a);
  *result -= b;
  return *result;
}

VeryLongInt &operator*(const VeryLongInt &a, const VeryLongInt &b) {
  VeryLongInt * result;
  result = new VeryLongInt(a);
  *result *= b;
  return *result;
}

VeryLongInt &operator/(const VeryLongInt &a, const VeryLongInt &b) {
  VeryLongInt * result;
  result = new VeryLongInt(a);
  *result /= b;
  return *result;
}

VeryLongInt &operator%(const VeryLongInt &a, const VeryLongInt &b) {
  VeryLongInt * result;
  result = new VeryLongInt(a);
  *result %= b;
  return *result;
}

VeryLongInt &operator<<(const VeryLongInt &a, unsigned int b) {
  VeryLongInt * result;
  result = new VeryLongInt(a);
  *result <<= b;
  return *result;
}

VeryLongInt &operator>>(const VeryLongInt &a, unsigned int b) {
  VeryLongInt * result;
  result = new VeryLongInt(a);
  *result >>= b;
  return *result;
}

bool operator==(const VeryLongInt &a, const VeryLongInt &b) {
  if (not (a.isValid() && b.isValid()))
    return false;
  return ((a - b).isValid() && (b - a).isValid());
}

bool operator!=(const VeryLongInt &a, const VeryLongInt &b) {
  if (not (a.isValid() && b.isValid()))
    return false;
  return not (a == b);
}

bool operator<(const VeryLongInt &a, const VeryLongInt &b) {
  if (not (a.isValid() && b.isValid()))
    return false;
  return ((b - a).isValid() && not (a - b).isValid());
}

bool operator<=(const VeryLongInt &a, const VeryLongInt &b) {
  if (not (a.isValid() && b.isValid()))
    return false;
  return (b - a).isValid();
}

bool operator>(const VeryLongInt &a, const VeryLongInt &b) {
  if (not (a.isValid() && b.isValid()))
    return false;
  return not (a <= b);
}

bool operator>=(const VeryLongInt &a, const VeryLongInt &b) {
  if (not (a.isValid() && b.isValid()))
    return false;
  return not (a < b);
}

ostream & operator<<(ostream & outputStream, const VeryLongInt & x) {
  if (not x.isValid()) 
    outputStream << "NaN";
  else if (x <= 9) 
    outputStream << x.data[0];
  else {
    VeryLongInt temp = x;
    stack<int> outputStack;
    while (temp > 0) {
      outputStack.push((temp % 10).data[0]);
      temp /= 10;
    }
    while (not outputStack.empty()) {
      outputStream << outputStack.top();
      outputStack.pop();
    }
  }
  return outputStream;
}

VeryLongInt const &Zero() {
  const static VeryLongInt global_zero = VeryLongInt();
  return global_zero;
}

VeryLongInt const &NaN() {
  const static VeryLongInt global_NaN = VeryLongInt(0) - VeryLongInt(1);
  return global_NaN;
}
