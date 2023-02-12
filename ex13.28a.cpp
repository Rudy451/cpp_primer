#include <iostream>
#include "ex13.28.h"

using namespace std;

int main(){

	TreeNode First("First");
	First.show_count();
	TreeNode Second("Second", First);
	First.show_count();
	Second.show_count();
	TreeNode Third("Third", Second);
	First.show_count();
	Second.show_count();
	Third.show_count();
	TreeNode Fourth("Fourth", Third);
	Fourth.show_count();
	TreeNode Fifth(Third);
	Fifth.show_count();
	TreeNode Sixth(Fourth);
	Sixth = Fifth;
	Sixth.show_count();
	cout << tot_ct << endl;
}
