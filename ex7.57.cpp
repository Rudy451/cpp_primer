#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

class Account
{
public:
	double calc(){return amount * ir;}
	static double rate(){return ir;}
private:
	std::string owner;
	double amount = 30000;
	static double ir;
	static const int period = 30;
	double daily_tlb[period];
};

double Account::ir = 1.10;

int main()
{
	Account WB;
	cout << WB.calc() << endl;

}
