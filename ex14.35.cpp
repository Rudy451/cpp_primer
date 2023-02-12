#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Print_Stuff{
public:
	string operator() (istream &input = cin){
		getline(input, ret_val);
		return ret_val.empty() ? "" : ret_val;
	}

private:
	string temp_val;
	string ret_val;

};

int main(){

	Print_Stuff Ftn;
	cout << Ftn() << endl;

}
