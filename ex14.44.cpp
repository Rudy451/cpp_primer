#include <iostream>
#include <functional>

using namespace std;

int add(double one, int two){return one + two;}
int subtract(int one, int two){return one - two;}
int multiply(int one, int two){return one * two;}
int divide(int one, int two){return one / two;}
int modulo(int one, int two){return one % two;}
int power(int one, int two){for(auto i = 0, j = one; i < two; ++i){one *= ((i == 0) ? 1 : j);}; return one;}

int desk_calculator(function<int(int, int)> action, int a, int b){return action(a, b);}

int main(){

	cout << desk_calculator(power, 2, 2) << endl;

}
