#include <iostream>
#include <vector>
#include <string>

// Figure out how to index screen

using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

class Window_Mgr{

public:
	void clear(int dim_x, int dim_y, int cursor);
private:
	int cursor = 0;

};

template<typename elemType> class Screen{

friend void Window_Mgr::clear(int dim_x, int dim_y, int cursor);

public:
	Screen() = default;
	Screen<elemType>(elemType x, elemType y): height(x), width(y) {};
	Screen<elemType>(elemType x, elemType y, string pos_mark): height(x), width(y), mark(pos_mark) {};
	
	Screen<elemType> &set(const string new_mark);
	Screen<elemType> &move(const elemType x_pos, const elemType y_pos);

private:
	elemType x_pos = 0;
	elemType y_pos = 0;
	elemType height = 10;
	elemType width = 10;
	string mark = "*";
};

void Window_Mgr::clear(int dim_x, int dim_y, int cursor){

	for(int cursor; cursor < dim_x * dim_y; ++cursor){
		if(cursor % dim_x == 0){
			cout << "o" << endl;
		} else {
			cout << "o";
		}
	}	
}

template<typename elemType> Screen<elemType> &Screen<elemType>::set(const string new_mark){

	mark = new_mark;
	return *this;

}

template<typename elemType> Screen<elemType> &Screen<elemType>::move(const elemType x_pos, const elemType y_pos){

	for(int row = 0; row < height; ++row){
		for(int col = 0; col < width; ++col){ 
			cout << ((x_pos == row && y_pos == col) ? mark : "o");
		}
		cout << endl;
	}

	return *this;

}

int main()
{
	Screen<int> myScreen(5, 5, "X");
	myScreen.set("#").move(3, 2);

}

