#include <iostream>
#include <algorithm>

using std::cout; using std::endl; 

int main(){

	int num = 5;

	auto num_stat = [&num]() -> bool {while(num != 0){--num;}; return (num == 0 ? 1 : 0);};
	cout << num_stat() << endl;

}
