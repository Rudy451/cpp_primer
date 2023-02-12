#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{

int x[10]; int *p = x;

cout << sizeof(x) << ", " << sizeof(*x) << ", " << sizeof(p) << ", " << sizeof(*p) << endl;
cout << sizeof(x) / sizeof(*x) << endl;
cout << sizeof(p) / sizeof(*p) << endl;

}


