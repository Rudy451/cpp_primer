#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static int HasPtr_Count = 0;

class HasPtr{

public:
	// Constructor
	HasPtr(const string &s = string()): ps(new string(s)), i(0) {++HasPtr_Count;}

	// Copy Constructor
	HasPtr(const HasPtr& orig): ps(orig.ps), i(orig.i) {++HasPtr_Count;}
	
	// Copy Assignment Operator
	HasPtr& operator=(HasPtr& orig){
		--HasPtr_Count;
		if(HasPtr_Count == 0){
			delete ps;
		}
		 ps = new string(*orig.ps);
		 i = orig.i;
	}

	// Less Than Operator
	bool operator<(const HasPtr& orig){
		return this->i < orig.i;
	}

	// Destructor 
	~HasPtr(){
		if(--HasPtr_Count == 0){
			delete ps;
		}
	}

	// Swap Function
	void swap(HasPtr &rhs);

	// Set Values
	void set_string(string val){*(this->ps) = val;}
	void set_num(int val){this->i = val;}

	// Print Function
	string print_string(){return *(this->ps);}
	void print_string_address(){cout << this->ps << endl;}
	int print_num(){return this->i;}

private:	
	// Data Members
	string *ps;
	int i;

};

vector<HasPtr> concat(HasPtr one, vector<HasPtr> two){

	vector<HasPtr> temp_vec;	
	temp_vec.push_back(one);
	for(auto start = 0; start < two.size(); ++start){
		temp_vec.push_back(two[start]);
	}
	return temp_vec;


}

vector<HasPtr> merge(vector<HasPtr> one, vector<HasPtr> two){

	HasPtr temp;

	if(one.empty()){
		return two;
	} else if(two.empty()){
		return one;
	} else if(one[0] < two[0]){
		temp = one[0];
		vector<HasPtr> temp_vec(one.begin() + 1, one.end());
		return concat(temp, merge(temp_vec, two));
	} else if(two[0] < one[0]){
		temp = two[0];
		vector<HasPtr> temp_vec(two.begin() + 1, two.end());
		return concat(temp, merge(one, temp_vec));
	}
}

vector<HasPtr> hasptr_sort(vector<HasPtr> vec, int n){

	if(n == 1){return vec;}
	auto mid = floor(vec.size() / 2);
	vector<HasPtr> one(vec.begin(), vec.begin() + mid);
	vector<HasPtr> two(vec.begin() + mid, vec.end());
	return merge(hasptr_sort(one, one.size()), hasptr_sort(two, two.size())); 
}

void HasPtr::swap(HasPtr &rhs){

	using std::swap;
	swap(this->ps, rhs.ps);
	swap(this->i, rhs.i);
	cout << "This Function Has Been Used." << endl;

}
	
int main(){


	HasPtr first("John Watson");
	first.set_num(5);
	HasPtr second("Jim Moriarty");
	second.set_num(4);
	HasPtr third("Sherlock Holmes");
	third.set_num(2);
	HasPtr fourth("Mycroft Holmes");
	fourth.set_num(3);
	HasPtr fifth("Euris Holmes");
	fifth.set_num(1);

	vector<HasPtr> char_list;
	char_list.push_back(first);
	char_list.push_back(second);
	char_list.push_back(third);
	char_list.push_back(fourth);
	char_list.push_back(fifth);

	vector<HasPtr> new_list = hasptr_sort(char_list, char_list.size());


	for(auto j = 0; j < new_list.size(); ++j){
		cout << new_list[j].print_string() << endl;
		cout << new_list[j].print_num() << endl;
	}

}
