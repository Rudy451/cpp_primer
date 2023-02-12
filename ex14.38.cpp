#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class StrLenComp{
public:
	StrLenComp(size_t min_val, size_t max_val): str_min(min_val), str_max(max_val) {}
	bool operator()(string str_comp){return ((str_comp.size() >= str_min) && (str_comp.size() <= str_max));}

private:
	size_t str_min;
	size_t str_max;

};

int main(int argc, char *argv[]){

	ifstream temp_strm(argv[1]);
	string temp_val;
	StrLenComp SLC_Ftn(1, 10);

	while(getline(temp_strm, temp_val)){
		stringstream sstrm(temp_val);
		string temp_val2;
		while(sstrm >> temp_val2){
			cout << SLC_Ftn(temp_val2) << " ";
		}
		cout << endl;
	}	

}
