#include <iostream>

using namespace std;

static int tot_ct = 1;

class BinStrTree;

class TreeNode{

public:

	friend class BinStrTree;
 
	// Constructors
	TreeNode(string entry): value(entry), count(tot_ct) {
		try{
			if(count > 1){throw "Can't Initialize with existing nodes";}
		} catch(const exception& e){
			cout << e.what() << endl;
		}
		if(tot_ct > 1){++tot_ct;}
	}

	TreeNode(string entry, TreeNode orig): value(entry), count(tot_ct + 1), left(new TreeNode(orig)) {
		try{
			if((count - orig.count) > 1){throw "Can't Initialize with out of sequence node";}
		} catch(const exception& e){
			cout << e.what() << endl;		
		}

		++tot_ct;
	}

	// Copy Constructor/
	TreeNode(const TreeNode& orig): value(orig.value), count(tot_ct + 1) {}

	// Copy Assignment Operator
	TreeNode& operator=(const TreeNode& orig){
		value = orig.value;
		count = tot_ct + 1;
	}

	~TreeNode(){}

	// Reveal Count;
	void show_count(){
		if(tot_ct < count){tot_ct = count;}
		cout << count << endl;
	}

private:
	string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};


class BinStrTree{

friend class TreeNode;

public:
// Default Constructor 
BinStrTree() = default;
// New Constructor
BinStrTree(TreeNode orig): root(new TreeNode(orig.value)){}

// Copy Constructor
BinStrTree(const BinStrTree& orig): root(new TreeNode(orig.root->value)){}

// Copy Assignment Operator
BinStrTree& operator=(const BinStrTree& orig){

	root = orig.root;

}

// Destructor
~BinStrTree(){
	cout << "Destruction Commence" << endl;
	delete root;
}
private:
        TreeNode *root;

};

