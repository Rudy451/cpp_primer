#include <fstream>
#include <sstream>
#include "ex12.22.h"

using std::ifstream; using std::istream; using std::stringstream; 

list<int> &sample_ftn(istream &ex, list<int> &Blob_list){

	string temp;
	string num;
	while(getline(ex, temp)){
		stringstream istr(temp);
		while(istr >> num){
			Blob_list.push_back(stoi(num));
		}
	}

	return Blob_list;

};

int main(int argc, char *argv[]){

	list<int> Blob_list;
	ifstream ex(argv[1]);
	const StrBlob Blob(sample_ftn(ex, Blob_list));
	auto blob_ptr = Blob.beg();
	for(size_t i = 0; i != Blob.size(); ++i){
		cout << blob_ptr.check_and_do(i) << endl;
	}
}
