#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using std::cout; using std::cin; using std::endl; using std::vector; using std::string; using std::istream; using std::ifstream; using std::istream_iterator; using std::copy; using std::back_inserter;

vector<string> vec_string;

int main(int argc, char* argv[]){

	ifstream i_file(argv[1]);
	istream_iterator<string> start(i_file), end;
	vector<string> vec_string(start, end);
	for_each(vec_string.begin(), vec_string.end(), [](const string &tst){cout << tst << " ";});
	cout << endl;
}
