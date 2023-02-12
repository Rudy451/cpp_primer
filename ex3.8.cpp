#include <iostream>
#include <string>


using std::cin; using std::cout; using std::string; using std::endl;

int main()
{

	string exp("abcdefghi");

	cout << "Original String: " << exp << endl;

	cout << "New String: ";

	for(auto c: exp){
		c = 'X';
		cout << c;
	}

	cout << endl;

	int i = 0;

	while(exp[i] != '\0'){
		auto d = 'X';
		cout << d;
		i++;
	}

	cout << endl;

	for(int i = 0; i < exp.size(); i++){
		auto e = 'X';
		cout << e;
	}

	cout << endl;

	return 0;	
}
