#include <iostream>

using namespace std;

struct SmallInt;

SmallInt operator+(const SmallInt& one, const SmallInt& two);

struct SmallInt{

	friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
	SmallInt(int i = 0): val(i) {};
	operator int() const {return val;}
private:
	std::size_t val;

};

SmallInt operator+(const SmallInt& one, const SmallInt& two){return one.val + two.val;}

int main(){

	SmallInt si;
	double d = si + SmallInt(3.14);
	cout << d << endl;

}
