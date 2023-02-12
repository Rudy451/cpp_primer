#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string s = "HAPPY";
	string t = s;
	string u = "HAPPY";
	string v(10, 'I');

	cout << s << ", " << t << ", " << u << ", " << v << endl;

	string a, b;
	cin >> a >> b;
	cout << a << ", " << b << endl;

	return 0;
}
