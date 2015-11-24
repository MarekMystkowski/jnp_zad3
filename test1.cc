#include "very_long_int.h"
#include <assert.h>
using namespace std;
void test_1(){
	VeryLongInt a(4);
	assert( a.isValid() );
	
	VeryLongInt b(2);
	assert( a != b);
	a = 2;
	assert( a == b);
	
	VeryLongInt O;
	assert( O == 0 );
	assert( a.isValid() );
	/*
	 NA FORUM JEST INFORMACJA O TYM PRZYPADKU:
	     Aktualnie przyjmuję że jest poprawne, zrzutuje binarnie na liczbę
	     bez znaku.
	VeryLongInt d(-1);
	assert(not d.isValid() );*/
	a -= 5;
	assert(not a.isValid() );
	
	char c[3]; c[0] = '4'; c[1] = '2'; c[2] = '\0';
	assert(VeryLongInt("42") == 42);
	assert(VeryLongInt(c) == 42);
	assert(VeryLongInt( string("42") ) == 42);
	//a += "42"; //Ma się nie kompilować :                              OK.
	// a = string("42"); // Ma się nie kompilować:                      OK
	//VeryLongInt q('4'); // Ma się nie kompilować:                     KOMPILUJE SIĘ !!!!!!!!!
	
	
}

void test_2(){
	VeryLongInt a(13);
	VeryLongInt b(4);
	assert( a + b == 17);
	assert( a - b == 9);
	assert( a * b == 52);
	assert( a / b == 3);
	assert( a % b == 1);

	assert( a << 1 == 26);
	assert( a >> 1 == 6); 
	a += b;
	assert(a == 17);
	assert(b == 4);
	a -= b;
	assert(a == 13);
	assert(b == 4);
	a *= b;
	assert(a == 52);
	assert(b == 4);
	a /= b;
	assert(a == 13);
	assert(b == 4);
	a /= b;
	assert(a == 3);
	a %= 2;
	assert(a == 1);
	a >>= 1;
	assert(a == 0);
	a >>= 1;
	assert(a == 0);
	a <<= 1;
	assert(a == 0);
	a += 3;
	a <<= 2;
	assert(a == 12);
	
}

void test_3(){
	VeryLongInt a;
	a = 4;
	assert(a);
	a = 0;
	assert( not a);
	a -= 3;
	assert( not a);
	//a = true; // Ma się nie kompilować:                               KOMPILUJE SIĘ !!!!!!!!!
}

int main(){
	test_1();
	test_2();
	test_3();
}
