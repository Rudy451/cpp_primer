#include <iostream>
#include <memory>
#include <list>

using namespace std;
static int ct;

template<typename t> class shr_ptr{

public:
	// Constructors
	shr_ptr() = default;
	shr_ptr(t val): p(new t(val)){++ct;}

	// Copy Assignment Operator
	shr_ptr& operator=(const shr_ptr& ex){++ct; p = ex.p; return *this;}

	// Destructor
	virtual ~shr_ptr(){--ct; if(ct == 0){delete p;}}
	
	// Reset Functions
	virtual void reset(){ct = 0; delete p;}
	virtual void reset(shr_ptr &q = nullptr){p = q.p;}

	// Get Pointer
	virtual t *get_ptr(){return this->p;}	

	// Get Me
	virtual shr_ptr<t> get_me(){return *this;}

protected:	
	t *p;
};

template<typename t> class wk_ptr : public shr_ptr<t>{

public:
	// Constructor
	wk_ptr() = default;
	wk_ptr(shr_ptr<t> q): w_p(q.get_ptr()) {}

	// Destructor
	~wk_ptr(){delete w_p;}

	// Use Count	
	int use_count() const {return ct;}

	// Expiration Status
	bool expired() const {return (ct == 0);}

	// Lock
	t *lock() const {return (this->expired() ? nullptr : this->w_p);}

	// Reset Function
	void reset(){delete w_p;}

	// Get Pointer
	t *get_ptr(){return this->w_p;}

private:	
	t *w_p;

};

template<typename t> class uni_ptr{

public:
	// Constructors
	uni_ptr() = default;
	uni_ptr(t *q = nullptr): p(q) {}

	// Destructor
	~uni_ptr(){delete p;}

	// Release
	void release(){this->p = nullptr;}

	// Reset Functions
	void reset(){delete p;}
	void reset(uni_ptr &q = nullptr){p = q.p;}

private:
	t *p;

};

template<typename t> shr_ptr<t> make_share(t val){return shr_ptr<t>(val);}

int main(){

        shr_ptr<list<int>> ex1 = make_share<list<int>>({1, 2, 3});
	cout << *(ex1.get_ptr()->begin()) << endl;
}
