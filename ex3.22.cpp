#include <iostream>
#include <string>
#include <vector>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	vector<string> text = {"Hi, my name is Bob.", "I like Rock N' Roll.", "I like to play games.", "Be my friend."};

	for(auto iter = text.begin(); iter != text.end(); ++iter){
		if(iter == text.begin()){
			for(auto &j: *iter){
				j = toupper(j);
			}
		}
		cout << *iter << endl;
	}

	return 0;
}
