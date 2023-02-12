#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename T> void print_stuff(T &stuff){

	typedef typename T::iterator iter;

	for(iter i = stuff.begin(); i < stuff.end(); ++i){
		cout << *(i) << " ";
	}
	cout << endl;

}

int main(){

vector<int> wtf = {1, 3, 5, 7, 9};
print_stuff(wtf);

vector<string> wtd = {"What", "The", "Dude", "?"};
print_stuff(wtd);

}
