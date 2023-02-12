#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

char vowel, vowel2;
int index, vowelCnt, spaceCnt, seqCnt = 0;

int main()
{

	cout << "Please enter your sentence and please remember to conclude with a period... " << endl;
	string sentence;
	getline(cin, sentence);
	while(index != sentence.size()){
		vowel = sentence[index];
		if(isspace(vowel)){
			++spaceCnt;
		}
		switch(vowel){
			case 'A': case 'E': case 'I': case 'O': case 'U':
				++vowelCnt;
				break;
			case 'a': case 'e': case 'i': case 'o': case 'u':
				++vowelCnt;
				break;
			case 'f':
				switch(sentence[index+1]){
					case 'f': case 'l': case 'i':
						++seqCnt;
						break;
				}
		}
		++index;
	}
	cout << endl;
	cout << "Total Vowels: " << vowelCnt << endl;
	cout << "Total Spaces: " << spaceCnt << endl;
	cout << "Total Sequences: " << seqCnt << endl;
}


