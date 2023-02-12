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

template<typename elemType, typename targetType> class Screen{

friend void Window_Mgr::clear(int dim_x, int dim_y, int cursor);
friend std::istream& operator>>(std::istream &input, targetType &val){input >> val >> endl;}
friend std::ostream& operator<<(std::ostream &output, Screen<elemType, targetType> &ex){

	for(auto row = 0; row < ex.height; ++row){
		for(auto col = 0; col < ex.width; ++col){
			cout << ((ex.x_pos == row && ex.y_pos == col) ? ex.mark : "o");
		}
		cout << endl;
	}

	return cout;

}

public:
	Screen() = default;
	Screen<elemType, targetType>(elemType x, elemType y): height(x), width(y) {};
	Screen<elemType, targetType>(elemType x, elemType y, targetType pos_mark): height(x), width(y), mark(pos_mark) {};
	
	Screen<elemType, targetType> &set(const targetType new_mark);
	Screen<elemType, targetType> &move(const elemType x_pos, const elemType y_pos);
	
private:
	elemType x_pos = 0;
	elemType y_pos = 0;
	elemType height = 10;
	elemType width = 10;
	targetType mark = "*";
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

template<typename elemType, typename targetType> Screen<elemType, targetType> &Screen<elemType, targetType>::set(const targetType new_mark){

	mark = new_mark;
	return *this;

}

template<typename elemType, typename targetType> Screen<elemType, targetType> &Screen<elemType, targetType>::move(const elemType newx, const elemType newy){

	for(int row = 0; row < height; ++row){
		for(int col = 0; col < width; ++col){ 
			cout << ((newx == row && newy == col) ? mark : "o");
			x_pos = newx;
			y_pos = newy;
		}
		cout << endl;
	}


	return *this;

}

int main()
{
	Screen<int, string> myScreen(5, 5, "X");
	myScreen.set("#").move(3, 2);
	cout << endl;
	cout << myScreen << endl;
}


