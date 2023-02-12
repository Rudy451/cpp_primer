#include <iostream>
#include <stack>
#include <string>

using std::stack; using std::cout; using std::endl; using std::string;

void stack_updater(stack<string> &value_list, string value){

	string temp;

	for(size_t i = 0; i < value.size(); ++i){
		if(value[i] == '('){
			cout << "SEEN THAT PARENS THO!" << endl;
			value_list.push("(");
		} else if(value[i] == ')'){
			break;
		} else if(value[i] == ' '){
			value_list.push(temp);
			temp.clear();
		} else { 
			temp.push_back(value[i]);
		}
	}

	while(!value_list.empty()){
		value_list.pop();
	}

	value_list.push("Done");
}	


int main(){

	stack<string> value_list;

	stack_updater(value_list, "(This is it)");

	cout << value_list.top() << endl;

	return 0;
	
}
