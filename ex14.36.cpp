#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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
	vector<string> PSF_Vec;
	while(cin){
		PSF_Vec.push_back(Ftn());
	}
	PSF_Vec.pop_back();

	for(auto i = 0; i < PSF_Vec.size(); ++i){
		cout << PSF_Vec[i] << endl;
	}

}
