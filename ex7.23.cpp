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

class Screen{

friend void Window_Mgr::clear(int dim_x, int dim_y, int cursor);

public:
	Screen() = default;
	Screen(int x, int y): height(x), width(y) {};
	Screen(int x, int y, string pos_mark): height(x), width(y), mark(pos_mark) {};
	
	Screen &set(const string new_mark);
	Screen &move(const int x_pos, const int y_pos);

private:
	int x_pos = 0;
	int y_pos = 0;
	int height = 10;
	int width = 10;
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

Screen &Screen::set(const string new_mark){

	mark = new_mark;
	return *this;

}

Screen &Screen::move(const int x_pos, const int y_pos){

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
	Screen myScreen(5, 5, "X");
	myScreen.set("#").move(3, 2);

}

