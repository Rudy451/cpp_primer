#include <iostream>
#include <string>
#include <set>

using namespace std;

class Folder;

class Message{

public:
	explicit Message(const string &str = ""): contents(str) {};
	Message(Message&& m) noexcept;
	Message& operator=(Message&& rhs) noexcept;
	Message(const Message& m);
	Message& operator=(const Message& rhs);
	~Message();
	void save(Folder&);
	void remove(Folder&);
	string new_msg(string str_value){this->contents = str_value;};
private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
friend class Folder;
friend void swap(Message &lhs, Message &rhs);


};

class Folder{

public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder(){};
private:
	set<Message*> msgs;
	void addMsg(Message* const);
	void remMsg(Message* const);
	void clearMsgs();
friend class Message;
friend void swap(Message &lhs, Message &rhs);

};

void Message::save(Folder &f){

	folders.insert(&f);
	f.addMsg(this);

}

void Message::remove(Folder &f){

	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m){

	for(auto f : m.folders){
		f->addMsg(this);
	}

}

void Message::remove_from_Folders(){

	for(auto f : folders){
		f->remMsg(this);
	}

}

// Move Constructor
Message::Message(Message&& m) noexcept: contents(m.contents), folders(m.folders){

	add_to_Folders(*this);
	m.remove_from_Folders();
	for(auto f : m.folders){
		f = nullptr;
	}
}

// Move-Assignment Operator
Message& Message::operator=(Message&& rhs) noexcept{

	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	for(auto f : rhs.folders){
		f = nullptr;
	}
	return *this;

}

// Copy Constructor
Message::Message(const Message& m): contents(m.contents), folders(m.folders){add_to_Folders(m);}

// Copy-Assignment Operator
Message& Message::operator=(const Message& rhs){

	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);	
	return *this;

}

Message::~Message(){remove_from_Folders();}


void Folder::addMsg(Message* const msg){

	this->msgs.insert(msg);
}

void Folder::remMsg(Message* const msg){
	
	this->msgs.erase(msg);

}

void Folder::clearMsgs(){

	for(auto m : msgs){
		m->remove(*this);
	}

}

void swap(Message &lhs, Message &rhs){

	using std::swap;
	for(auto f: lhs.folders){f->remMsg(&lhs);} 
	for(auto f: rhs.folders){f->remMsg(&rhs);}
	swap(lhs.folders, rhs.folders);	
	swap(lhs.contents, rhs.contents);
	for(auto f: lhs.folders){f->addMsg(&lhs);}
	for(auto f: rhs.folders){f->addMsg(&rhs);}
}

int main(){

	Folder first;
	Message One;
	One.new_msg("Dear John");
	One.save(first);
	Message Two = std::move(One);

}
