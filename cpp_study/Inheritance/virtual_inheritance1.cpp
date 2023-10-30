#include <iostream>

using namespace std;

class Person {
public:
	Person() {
		cout << "Person::Person 생성자" << endl;
	} 
	~Person() {
		cout << "Person::Person 소멸자" << endl;
	}
	virtual void write() = 0;
};

class Chulsoo : public virtual Person { // 가상 상속
public:
	Chulsoo() :Person() {
		cout << "Chulsoo::Chulsoo() 생성자" << endl;
	}
	~Chulsoo() {
		cout << "Chulsoo::Chulsoo() 소멸자" << endl;
	}
	void write() {
		cout << "책을 잘 쓴다" << endl;
	}
};

class Younghee : public virtual Person {
public:
	Younghee() : Person() {
		cout << "Younghee::Younghee() 생성자" << endl;
	}
	~Younghee() {
		cout << "Younghee::Younghee() 소멸자" << endl;
	}
	void write() {
		cout << "책을 못 쓴다" << endl;
	}
};

class Youngchul : public Chulsoo, public Younghee {
public :
	Youngchul() : Chulsoo(), Younghee() {
		cout << "Youngchul::Youngchul() 생성자" << endl;
	 }
	~Youngchul() {
		cout << " Youngchul::~Youngchul() 소멸자" << endl;
	}
	void write() {
		//write();
		Chulsoo::write();
	}
};

int main() {
	Youngchul youngchul;
	youngchul.write();
	return 0;
}