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
	
	VeryLongInt c(-1);
	assert(not c.isValid() );
	a = -5;
	assert(not a.isValid() );
}

int main(){
	test_1();
}
