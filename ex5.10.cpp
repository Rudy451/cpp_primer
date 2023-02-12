#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

char vowel;
int vowelCnt = 0;

int main()
{

	while(cin >> vowel){
		if(vowel == 'A' || vowel == 'a'){
			++vowelCnt;
		} else if(vowel == 'E' || vowel == 'e'){
			++vowelCnt;
		} else if(vowel == 'I' || vowel == 'i'){
			++vowelCnt;
		} else if(vowel == 'O' || vowel == 'o'){
			++vowelCnt;
		} else if(vowel == 'U' || vowel == 'u'){
			++vowelCnt;
		}
	}
	cout << endl;
	cout << "Total Vowels: " << vowelCnt << endl;
}


