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

	for(int i = 0; i < v8.size(); ++i){
        	if(v8[i].empty()){
                	cout << "This vector is empty" << endl;
                } else {
                        cout << "List of Elements: ";
                        for(int j = 0; j < v8[i].size(); ++j){
                                cout << v8[i][j] << ", ";
                        }
                        cout << endl;
                   	cout << "Vector Size: " << v8[i].size() << endl;
		}
	}

	for(int i = 0; i < v9.size(); ++i){
		if(v9[i].empty()){
			cout << "This vector is empty";
		} else{
           		cout << "List of Elements: ";
               		for(auto j: v9[i]){
                     		cout << j << ", ";
                        }
                        cout << endl;
                        cout << "Vector Size: " << v9[i].size() << endl;
                }

        }	
    
	return 0;	
}
