#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	cout << "bool size: " << sizeof(bool) << endl;
	cout << "char size: " << sizeof(char) << endl;
	cout << "wide character size: " << sizeof(wchar_t) << endl;
	cout << "unicode character size (32): " << sizeof(char16_t) << endl;
	cout << "unicode character size (64): " << sizeof(char32_t) << endl;
	cout << "int size: " << sizeof(int) << endl;
	cout << "short size: " << sizeof(short) << endl;
	cout << "long size: " << sizeof(long) << endl;
	cout << "long long size: " << sizeof(long long) << endl;
	cout << "float size: " << sizeof(float) << endl;
	cout << "double size: " << sizeof(double) << endl;

}


