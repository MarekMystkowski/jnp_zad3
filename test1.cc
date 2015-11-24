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
	
	VeryLongInt d(-1);
	assert(not d.isValid() );
	a = -5;
	assert(not a.isValid() );
	
	char c[3]; c[0] = '4'; c[1] = '2'; c[2] = '\0';
	assert(VeryLongInt("42") == 42);
	assert(VeryLongInt(c) == 42);
	
}

void test_2(){
	VeryLongInt a(13);
	VeryLongInt b(4);
	assert( a + b == 17);
	assert( a - b == 9);
	assert( a * b == 52);
	assert( a / b == 3);
	assert( a % b == 1);
/*
	assert( a << 1 = 26);
	assert( a >> 1 = 6); */
}


int main(){
	test_1();
	test_2();
}
