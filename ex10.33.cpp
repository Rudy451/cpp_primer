#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using std::cout; using std::cin; using std::endl; using std::vector; using std::string; using std::ifstream; using std::ofstream; using std::istream_iterator; using std::ostream_iterator; using std::copy; using namespace std::placeholders;

void strm_ins(ostream_iterator<int> strm_one, ostream_iterator<int> strm_two, int num){

	if(num % 2){
		*strm_one++ = num;
	} else {
		*strm_two++ = num;
	}

}

int main(int argc, char* argv[]){

	ifstream i_file(argv[1]);
	ofstream odd_file(argv[2]), even_file(argv[3]);
	istream_iterator<int> start(i_file), end;
	ostream_iterator<int> odd_iter(odd_file, " "), even_iter(even_file, " ");
	vector<int> int_vec(start, end);
	sort(int_vec.begin(), int_vec.end());
	for_each(int_vec.begin(), int_vec.end(), bind(strm_ins, odd_iter, even_iter, _1));

}
