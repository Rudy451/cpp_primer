#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	string s = "word";
	string pl = ((s + s[s.size() + 1] == "s") ? "" : "s");
	cout << pl << endl;
}


