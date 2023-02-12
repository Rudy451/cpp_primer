#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main(){

	int n = 200;
	string s;
	allocator<string> alloc;
	const auto p = alloc.allocate(n);
	string *q = p;
	while(cin >> s && q != p + n){
		alloc.construct(q++, s);
	}

	while(q != p){
		cout << *(q - 1) << endl;
		alloc.destroy(--q);
	}
	
	alloc.deallocate(p, n);		
}
