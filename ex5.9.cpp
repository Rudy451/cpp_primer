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
		if(vowel == 'a'){
			++vowelCnt;
		} else if(vowel == 'e'){
			++vowelCnt;
		} else if(vowel == 'i'){
			++vowelCnt;
		} else if(vowel == 'o'){
			++vowelCnt;
		} else if(vowel == 'u'){
			++vowelCnt;
		}
	}

	cout << "Total Vowels: " << vowelCnt << endl;
}


