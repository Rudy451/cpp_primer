#include <iostream>
#include "ex13.39.h"


int main(){

	StrVec first({"Francis", "Dolarhyde"});
	StrVec second = std::move(first);
	second.remove_element();
	second.remove_element();
	second.add_element("Jake");
	second.add_element("Gumb");
	second.print_elements();		
}
