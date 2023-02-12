#include <iostream>
#include <typeinfo>

using std::cin; using std::cout; using std::endl;

int main()
{
	// NOTE: Overflow occurs when a value is computed that exceeds the range of values its type can represent.

	// first example: shorts can have max of 32767. Output = -32768 b/c value was wrapped around with negative sign.
	short ex_1 = 32768;
	cout << ex_1 << endl;
	
	// second example: longs can have max of 2147483647. Output = actual value (maybe unsigned version?).
	long ex_2 = 2147483651;
	cout << ex_2 << endl;

	// third example: longs can have max of 9223372036854775808. Output = negative b/c value was wrapped around.
	long long ex_3 = 9223372036854775808;
	cout << ex_3 << endl;
}
