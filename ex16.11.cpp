#include <iostream>

template<typename elemType> class ListItem;
template<typename elemType> class List{

public:
	List<elemType>();
	List<elemType>(const List<elemType> &);
	~List();
	void insert(ListItem<elemType> *ptr, elemType value);
private:
	ListItem<elemType> *front, *end;

};

int main(){



}
