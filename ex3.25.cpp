#include <iostream>
#include <string>
#include <vector>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;


int main()
{
	// Rewrite the grade clustering program from 3.3.3 (p. 104) using iterators instead of subscripts
	vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
	unsigned grade;
	while(cin >> grade){
		int i = 10;
		for(auto iter = scores.begin(); iter != scores.end(); ++iter){
			if(grade < i){
				++*(iter);
				break;
			}
			i += 10;
		}
	}


	for(auto iter = scores.begin(); iter != scores.end(); ++iter){
		cout << *iter << endl;
	}
}
