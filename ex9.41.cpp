#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::endl; using std::vector; using std::string;

int main(){

	vector<char> first = {'D', 'a', 'n', 'e', '/'};

	string second;
	string third;

	auto i = 0;
	auto j = (first.size() / 2);

	while(1){
		if(i < first.size() / 2){
			second.push_back(first[i]);
			++i;
		}

		if(j < first.size()){
			third.push_back(first[j]);
			++j;
		}

		if( i == ((first.size()) / 2) && j == first.size()){
			break;
		}
	}

	second.insert(second.end(), third.begin(), third.end());

	cout << second.size() << endl;

}
