#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cout; using std::cin; using std::endl; using std::vector; using std::istream_iterator; using std::ostream_iterator; using std::copy;

int main(){

	istream_iterator<int> i_start(cin), i_end;
	ostream_iterator<int> o_strm(cout, " ");
	vector<int> temp_vec(i_start, i_end);
	sort(temp_vec.begin(), temp_vec.end());
	auto temp_vec_spot = unique(temp_vec.begin(), temp_vec.end());
	copy(temp_vec.begin(), temp_vec_spot, o_strm);
	o_strm;
}
