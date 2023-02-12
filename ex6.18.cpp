#include <iostream>
#include <string>
#include <vector>
#include "ex6.18.h"

using std::cin; using std::cout; using std::vector; using std::string; using std::endl;

	vector<int> vec = {1, 2, 3, 4, 5, 6, 3.8, 4};
	
	int count(const string &word, char letter){
		int total = 0;
		for(char i : word){
			if(i == letter){
				++total;
			}
		}

		return total;
	}

	int sum(vector<int>::iterator iterator_1, vector<int>::iterator iterator_2, int total=0){
		for(iterator_1; iterator_1 != iterator_2; ++iterator_1){
			total += *(iterator_1);
		};

		return total;
	}

int main()
{
	cout << calc(23) << endl;
	cout << count("abcda", 'a') << endl;
	cout << calc(66) << endl;
	cout << sum(vec.begin(), vec.end(), 3.8) << endl;
}
