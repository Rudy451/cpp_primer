#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename T> void print_stuff(T &stuff){

	typedef typename T::size_type val;	
	typedef typename T::iterator iter;

	iter start = stuff.begin();
	
	for(val i = 0; i < stuff.size(); ++i){
		cout << *(start++) << " ";
	}
	cout << endl;

}

int main(){

vector<int> wtf = {1, 3, 5, 7, 9};
print_stuff(wtf);

vector<string> wtd = {"What", "The", "Dude", "?"};
print_stuff(wtd);

}
