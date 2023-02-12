#include <iostream>

using std::cin; using std::cout; using std::endl;

int count(void){
	static int cnt = 0;
	return ++cnt;

}

int main()
{
	cout << "Enter a number & we'll print its sequence: " << endl;
	int tot;
	cin >> tot;
	
	for(int i = 0; i < tot; ++i){
		cout << count() << endl;
	}

}


// Second approach

//	for(int i = 0; i < sentence.size(); ++i){
//		int count = 1;
//		for(int j = i + 1; j < sentence.size(); ++j){
//			if(sentence[i] == "NULL" || sentence[j] == "NULL"){
//				break;
//			} else if(sentence[i] == sentence[j]){
//				++count;
//				sentence[j] = "NULL";
//			}
//		}
//
///		if(sentence[i] != "NULL"){cout << sentence[i] << " count: " << count << endl;}
//		
//	}

