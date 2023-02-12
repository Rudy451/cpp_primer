#include <iostream>
#include <string>
#include <vector> 

using std::cout; using std::endl; using std::string; using std::vector; using std::min; using std::cerr;

vector<unsigned> dates;

unsigned month_to_dig(string date){

	if(date.find("Jan") != string::npos){
		return 1;
	} else if(date.find("Feb") != string::npos){
		return 2;
	} else if(date.find("Mar") != string::npos){
		return 3;
	} else if(date.find("Apr") != string::npos){
		return 4;
	} else if(date.find("May") != string::npos){
		return 5;
	} else if(date.find("Jun") != string::npos){
		return 6;
	} else if(date.find("Jul") != string::npos){
		return 7;
	} else if(date.find("Aug") != string::npos){
		return 8;
	} else if(date.find("Sep") != string::npos){
		return 9;	
	} else if(date.find("Oct") != string::npos){
		return 10;
	} else if(date.find("Nov") != string::npos){
		return 11;
	} else if(date.find("Dec") != string::npos){
		return 12;	
	} else {
		return 0;
	}
}

vector<unsigned> conv_to_date(string temp, vector<unsigned> &dates){

	string months = "JanFebMarAprMayJunJulyAugSepOctNovDec";
	string days = "0123456789";
	auto pos_date = 0;
	auto pos_sign = 0;

	for(size_t i = 0; i < 3; ++i){
		if(*temp.begin() == ' '){
			temp.erase(temp.begin());
		}

		if((pos_sign = min(min(temp.find_first_of(' '), temp.find_first_of(", ")), temp.find_first_of("/"))) != string::npos){
			if((pos_date = temp.find_first_of(months)) != string::npos){
				dates.push_back(month_to_dig(temp.substr(pos_date, pos_sign)));
				temp = temp.substr(pos_sign + 1);
			} else if((pos_date = temp.find_first_of(days)) != string::npos){
				dates.push_back(stoul(temp.substr(pos_date, pos_sign)));
				temp = temp.substr(pos_sign + 1);
			} else {
				cerr << "PLEASE USE A VALID DATE!" << endl;
				return dates;
			}
		} else if(i == 2){
			dates.push_back(stoul(temp.substr(temp.find_first_of(days))));	
		} else {
			cerr << "PLEASE USE A VALID SIGN!" << endl;
			return dates;
		}

		pos_date = 0;
		pos_sign = 0;
	}	

	return dates;
}



struct date{

// Contructors
date(string temp){
	dates = conv_to_date(temp, dates);
	month = dates[0];
	day = dates[1];
	year = dates[2];
};

// Properties
unsigned year;
unsigned month;
unsigned day;

};

int main(){

	date first("January 1, 2010");
	cout << first.month << endl;
	cout << first.day << endl;
	cout << first.year << endl;
		
}
