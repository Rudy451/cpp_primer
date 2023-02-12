#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{

// Given variables:
 int i; double d; const char *ps; char *pc; void *pv;

// OLD: pv = (void*)ps
pv = static_cast<void*>(const_cast<char*>(ps));
// ERROR: Const_cast can only change constness not type

// OLD: i = int(*pc)
// Can't use reinterpret_cast b/c precision lost. Will use atoi instead
i = atoi(pc);

// OLD: pv = &d
pv = &d;

// OLD: pc = (char*)pv
pc = static_cast<char*>(pv);

}


