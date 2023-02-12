#include <iostream>

class Debug{

public:
	Debug() = default;
	Debug(h, i, o): hw(h), io(i), other(o) {}
	Debug(bool b = true): hw(b), io(b), other(b) {}

	bool which() {return hw || io || other;}
	
private:
	bool hw;
	bool io;
	bool other;
};

int main()
{

	return 0;
}
