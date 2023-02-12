#include <iostream>

using namespace std;

struct SmallInt{

	friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
	SmallInt(int = 0){};
	operator int() const {return val;}
private:
	std::size_t val;

};

struct LongDouble{

	LongDouble operator+(const SmallInt& two){return two + two;}

};

LongDouble operator+(LongDouble& one, double two){return one + two;}

int main(){

	SmallInt si;
	LongDouble ld;
	//ld = si + ld;
	ld = ld + si;

}
