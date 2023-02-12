#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;

class Coach{
	public: virtual void task(){
		cout << "Lead" << endl;
	}
};

class Coordinator : public Coach{

	public: void task(){
		cout << "Design" << endl;
	}
};

void duty(Coach *Person){
		Person->task();
}

int main(){

	Coach *Head = new Coach;
	Coordinator *Offense = new Coordinator;

//	Belichick.task();
//	McDaniels.task();

	duty(Head);
	duty(Offense);

	return 0;

}

