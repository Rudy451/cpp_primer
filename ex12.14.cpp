#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>

using std::cout; using std::endl; using std::vector; using std::string; using std::shared_ptr; using std::make_shared; using std::runtime_error;

struct connection{};

connection connect(){
	
	cout << "Connecting..." << endl;
	connection c;
	return c;

}

void end_connect(connection *p){

	cout << "Disconnecting... " << endl;
	delete p;
}

void connect_mgr(){

	connection c = connect();
	shared_ptr<connection> p(new connection(c), end_connect);
	throw 42;
}

int main(){

	try{
		connect_mgr();
	} catch (...){
		cout << "Game Over" << endl;
	}
	
	return 0;
}
