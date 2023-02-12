#include <iostream>
#include <string>

using namespace std;

class Pick_One{
public:
	string operator() (string one, string two, string three){
		return ((one == "Bruce_Wayne") ? two : three);
	}

};

int main(){

	Pick_One Ftn;
	cout << Ftn("Bruce_Wayne", "Batman", "Superman") << endl;

}
