#include <iostream>
#include <string>

using std::string;

bool str_subrange(const string &str1, const string &str2)
{
	// same sizes: return normal equality test
	if(str1.size() == str2.size()){
		return str1 == str2;
	}

	// find the size of the smaller string; conditional operator
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

	// look at each element up to the size of the smaller string
	for(decltype(size) i = 0; i != size; ++i){
		if(str1[i] != str2[i]){
			// Error: no return value; compiler should detect this
			return;
		}
	}

	// Error: Control might flow off the end of the function without a return 
	// The compiler might not detect this error.

}

int main()
{
	const string word_1 = "Happy";
	const string word_2 = "Hap";
	str_subrange(word_1, word_2);
	
	return 0;
}
