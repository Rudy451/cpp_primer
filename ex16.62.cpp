#include <iostream>
#include <string>
#include <unordered_set>

struct blob{

	blob(std::string v1, int v2): name(v1), number(v2) {}
	std::string name = "";
	int number = 0;

};

bool operator==(const blob& one, const blob& two){

	return one.number == two.number;

}

bool operator<(const blob& one, const blob& two){ 
	return one.number < two.number;

}

namespace std{

	template<> struct hash<blob>{
		typedef size_t ret_val;
		typedef blob arg_type;
		size_t operator()(const blob& ex) const {
			return (hash<string>()(ex.name) ^ hash<int>()(ex.number));
		}
	};

}

int main(){

	blob first("Vince", 1985);
	blob second("Brandon", 1985);
	blob third("Banky", 1985);	
	blob fourth("Troy", 1987);
	blob fifth("Dane", 1990);	

	std::unordered_multiset<blob, std::hash<blob>> temp;

	temp.insert(first);
	temp.insert(second);
	temp.insert(third);
	temp.insert(fourth);
	temp.insert(fifth);
	
	for(auto i = temp.begin(); i != temp.end(); ++i){
		std::cout << "Name: " << i->name;
		std::cout << " Number: " << i->number << std::endl;
	}

}
