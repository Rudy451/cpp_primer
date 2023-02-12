#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl; using std::transform;

int main()
{
	string word;
	vector<string> seq;

	while(cin >> word){
		seq.push_back(word);
	}


	for(int i = 0; i < seq.size(); ++i){
		transform(seq[i].begin(), seq[i].end(), seq[i].begin(), ::toupper); // Technique to convert strings to uppercase on single line
		if(i % 8 != 0){
			cout << seq[i] << " ";
		} else {
			cout << endl;
			cout << seq[i] << " ";
		}
	}

	cout << endl;
    
	return 0;	
}
