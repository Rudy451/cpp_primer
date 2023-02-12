#include <iostream>
#include <vector>
#include <list>

using std::vector; using std::list; using std::cout; using std::endl;

int main(){

	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> ib; // even
	list<int> ic; // odd

	for(auto i = 0; i < (sizeof(ia) / sizeof(int)); ++i){
		ib.insert(ib.end(), ia[i]);
		ic.insert(ic.end(), ia[i]);	
	}
	

	vector<int>::iterator ib_temp = ib.begin();
	list<int>::iterator ic_temp = ic.begin(); 


	while(ib_temp != ib.end() && ic_temp != ic.end()){
		if(ib_temp != ib.end()){
			if(*(ib_temp) % 2){
				ib.erase(ib_temp);
				++ic_temp;
			}
		}
		 
		if(ic_temp != ic.end()){
			if(!(*(ic_temp) % 2)){
				ic_temp = ic.erase(ic_temp);
				++ib_temp;
			}
		}

	}

	cout << ib.size() << endl;
	cout << ic.size() << endl;

}
