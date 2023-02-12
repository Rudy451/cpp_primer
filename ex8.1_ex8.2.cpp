#include <iostream>
#include <string>

using std::istream; using std::string; using std::cin; using std::cout; using std::endl;

int num;

istream &random_ftn(istream &input, int num){
	while(input >> num){
		auto old_stream = input.rdstate();
		input.clear();
		cout << num << endl;
		input.setstate(old_stream);
	}
	return input;

}

int main(){
	random_ftn(cin, num);
	return 0;
}
