#include <iostream>

using std::cin; using std::cout; using std::endl;

int main(){

	int i = 50, j = 0;

	while(i <= 100){
		j += i;
		i++;
	}

	cout << j << endl;

	int k = 10;
	while(k >= 0){
		cout << k << endl;
		k--;
	}

	int l, m;

	cout << "Please enter two numbers: " << endl;

	cin >> l >> m;
	
	if(l < m){
		while(l <= m){
			cout << l << endl;
			l++;
		}
	} else if(m < l){
		while(m <= l){
			cout << m << endl;
			m++;		
		}
	} else {
		cout << "They're equal" << endl;
	}
}
