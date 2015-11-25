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

void test_4(){
	long long int x = 100000000000000000L;
	VeryLongInt a(x);
	assert( a == x);
	a += x;
	assert ( a == 2L * x);
	a = a + a + a + a;
	assert( a == 8L * x);
	a = 0;
	for( int i = 0; i < 10000 ; i++)
		a += x;
	
	for( int i = 0; i < 10000 ; i++)
		a -= x;
	
	assert( a == 0);
	
	long long int y = 4294967295L;
	a = y;
	a += 1;
	assert( a == y + 1L);
	a -= 2;
	assert( a == y - 1L);
	a = y; a += y;
	assert( a == 2L * y); 
	a -=  y + 1L;
	assert( a == y -1L );
}

void test_5(){
	VeryLongInt a, b;
	a = 2;
	a *= 2;
	assert( a == 4);
	long long int x = 1000000L;
	a = x;
	a *= x;
	assert( a == x *x);
	a *= x;
	assert( a == x *x * x);
	
}

void test_6(){
	VeryLongInt a("121212121212121212121212121212");
	VeryLongInt b("100000000000000000000000000000000");
	VeryLongInt c("121212121212121212121212121212"
				  "00000000000000000000000000000000");
	assert(a * b == c);
	
}

// Proste testy na podstawowe operatory 2 argumentowe, 10x:
void test_100(){
	VeryLongInt x = 1;
	assert(x == 1);
}

void test_101(){
	VeryLongInt x = 2;
	VeryLongInt y = 3;
	assert(x + y == 5);
	assert(y - x == 1);
}

void test_102(){
	VeryLongInt x = 4;
	VeryLongInt y = 5;
	assert(x * y == 20);
}

void test_103(){
	VeryLongInt x = 40;
	VeryLongInt y = 5;
	assert(x / y == 8);
}

void test_104(){
	VeryLongInt x = 14;
	VeryLongInt y = 5;
	assert(x % y == 4);
}

// Proste testy na operatory jedno argumentowe 11x:
void test_110(){
	VeryLongInt x = 1;
	VeryLongInt y = 0;
	x += y;
	assert(x == 1);
}

void test_111(){
	VeryLongInt x = 2;
	VeryLongInt y = 3;
	x += y;
	assert(x == 5);
	assert(y == 3);
	
	x -= y;
	assert(x == 2);
	assert(y == 3);
}

void test_112(){
	VeryLongInt x = 4;
	VeryLongInt y = 5;
	x *= y;
	assert(x == 20);
	assert(y == 5);
}

void test_113(){
	VeryLongInt x = 40;
	VeryLongInt y = 5;
	x /= y;
	assert(x == 8);
	assert(y == 5);
}

void test_114(){
	VeryLongInt x = 14;
	VeryLongInt y = 5;
	x %= y;
	assert(x == 4);
	assert(y == 5);
}

void test_115(){
	VeryLongInt x = 14;
	int y = 1;
	x >>= y;
	assert(x == 7);
	assert(y == 1);
}

void test_116(){
	VeryLongInt x = 6;
	int y = 3;
	x <<= y;
	assert(x == 48);
	assert(y == 3);
}

// Proste testy na operatory porównujące 12x:
void test_120(){
	VeryLongInt x = 1;
	VeryLongInt y = 2;
	assert(x < y);
}

void test_121(){
	VeryLongInt x = 1;
	VeryLongInt y = 2;
	assert(x <= y);
}

void test_122(){
	VeryLongInt x = 9;
	VeryLongInt y = 4;
	assert(x > y);
}

void test_123(){
	VeryLongInt x = 9;
	VeryLongInt y = 4;
	assert(x >= y);
}

void test_124(){
	VeryLongInt x = 1;
	VeryLongInt y = 1;
	assert(x == y);
}

void test_125(){
	VeryLongInt x = 1;
	VeryLongInt y = 2;
	assert(x != y);
}

void test_126(){
	VeryLongInt x = 1;
	VeryLongInt y = 1;
	assert(x <= y);
}

void test_127(){
	VeryLongInt x = 1;
	VeryLongInt y = 1;
	assert(x >= y);
}

void test_128(){
	VeryLongInt x = 1;
	VeryLongInt y = 1;
	assert(not(x < y));
}

void test_129(){
	VeryLongInt x = 8;
	VeryLongInt y = 2;
	assert(not(y >= x));
}


// Testy podane w treści zadania 100xy:

void test_1000(){
	VeryLongInt x = 1;
	x /= 0;
	assert(!x.isValid());
}

void test_10001(){
	VeryLongInt x = 100;
	x -= 101;
	assert(!x.isValid());
}

void test_10002(){
	VeryLongInt x = NaN();
	assert(!x.isValid());
}

void test_10003(){
	VeryLongInt x = 23;
	VeryLongInt y = x;
	assert(x == y);
}

void test_10004(){
	VeryLongInt x = 23;
	VeryLongInt y = 32;
	x = y;
	assert(x == y);
}

void test_10005(){
	VeryLongInt x = 23;
	VeryLongInt y = 32;
	assert(y > x);
}

void test_10006(){
	VeryLongInt x = 23;
	VeryLongInt y = 32;
	assert(y >= x);
}

void test_10007(){
	VeryLongInt x = 10;
	if (x)
		assert(1);
	else
		assert(0);
}
/*
void test_10008(){
	VeryLongInt x = 1;
	x <<= 1;
	assert(2 == x);
}

void test_10009(){
	VeryLongInt x = 8;
	x >>= 2;
	assert(2 == x);
}

void test_10010(){
	VeryLongInt x = 1;
	x <<= 123;
	x >>= 120;
	assert(8 == x);
}

void test_10011(){
	VeryLongInt x = 1;
	for (int i = 1; i <= 100; ++i)
		x *= 2;
	assert(x % 3 == 1);
}
*/
void test_10012(){
	VeryLongInt x = Zero() ;
	assert(x == 0);
}
/*
void test_10013(){
	const int N = 100;
	VeryLongInt x = 1;
	for (int i = 1; i < N; ++i)
		x *= 2;
	assert(x.numberOfBinaryDigits() == N);
}

void test_10014(){
	VeryLongInt x("1234567890123456789012345678901234567890");
	VeryLongInt z = x;
	VeryLongInt y("777777777777777777777777777777777777777");
	x = x + y;
	x -= y;
	assert(x == z);
}

void test_10015(){
	VeryLongInt x(string("12345678"));
	VeryLongInt y(12345678U);
	assert(x == y);
}

void test_10016(){
	VeryLongInt x("12345678901234567890");
	VeryLongInt y(12345678901234567890UL);
	assert(x == y);
	cout << y << endl;
}

void test_10017(){    
	VeryLongInt x("1234567890123456789012345678901234567890");
	VeryLongInt y("1204567890123456789012345678901234567890");
	VeryLongInt z(  "30000000000000000000000000000000000000");
	assert(z == x - y);
}

void test_10018(){
	VeryLongInt x("10000000000");
	VeryLongInt y("100000000000");
	VeryLongInt z("1000000000000000000000");
	assert(z == x * y);
}

void test_10019(){
	const int N = 1000;
	VeryLongInt x = 1;
    for (int i = 2; i <= N; ++i)    
		x *= i;

	for (int i = 2; i <= N; ++i)
		x /= i;
	
	assert(x == 1);
}

void test_10020(){
	assert(Zero().numberOfBinaryDigits() == 1);
	assert(NaN().numberOfBinaryDigits() == 0);
}

*/

int main(){
	
	VeryLongInt a = 123456789;
	cout << a << " = 123456789" << endl;
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	//test_6(); // Mnożenie dalej nie działa :(
	
	// Bardzo proste testy:
	test_100();
	test_101();
	test_102();
	test_103();
	test_104();
	
	test_110();
	test_111();
	test_112();
	test_113();
	test_114();
	test_115();
	test_116();
	
	test_120();
	test_121();
	test_122();
	test_123();
	test_124();
	test_125();
	test_126();
	test_127();
	test_128();
	test_129();
	
	// Testy z treści zadania:

	void test_10000();
	void test_10001();
	void test_10002();
	void test_10003();
	void test_10004();
	void test_10005();
	void test_10006();
	void test_10007();
	/*
	void test_10008();
	void test_10009();
	void test_10010();
	void test_10011();*/
	void test_10012();/*
	void test_10013();
	void test_10014();
	void test_10015();
	void test_10016();
	void test_10017();
	void test_10018();
	void test_10019();
	void test_10020();
	*/
	
}
