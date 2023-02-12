#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{10};
	vector<int> v5{10, 42};
	vector<string> v6{10};
	vector<string> v7{10, "hi"};

	vector<vector<int>>v8{v1, v2, v3, v4, v5};
	vector<vector<string>>v9{v6, v7};

	for(auto iter = v8.begin(); iter != v8.end(); ++iter){
        	if(iter->empty()){
                	cout << "This vector is empty" << endl;
                } else {
                        cout << "List of Elements: ";
                        for(auto iter_2 = iter->begin(); iter_2 != iter->end(); ++iter_2){
                                cout << *iter_2 << ", ";
                        }
                        cout << endl;
                   	cout << "Vector Size: " << iter->size() << endl;
		}
	}

	for(auto iter = v9.begin(); iter != v9.end(); ++iter){
		if(iter->empty()){
			cout << "This vector is empty";
		} else{
          		cout << "List of Elements: ";
               		for(auto j: *iter){
                     		cout << j << ", ";
                 	}
                        cout << endl;
                        cout << "Vector Size: " << iter->size() << endl;
               }

        }	
    
	return 0;	
}
