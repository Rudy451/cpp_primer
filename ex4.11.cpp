#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	int a, b, c, d;
	cout << "Key in four values: " << endl;
	cin >> a >> b >> c >> d;

	if(c < d){
		c += d;
	}

	if(b < c || b < d){
		b += c + d;
	}

	if(a < b || a < c || a < d){
		a += b + c + d;
	} 

	cout << a << ", " << b << ", " << c << ", " << d << endl;
}


