#include <iostream>

using namespace std;

class Person {
public:
	Person() {
		cout << "Person::Person ������" << endl;
	} 
	~Person() {
		cout << "Person::Person �Ҹ���" << endl;
	}
	virtual void write() = 0;
};

class Chulsoo : public virtual Person { // ���� ���
public:
	Chulsoo() :Person() {
		cout << "Chulsoo::Chulsoo() ������" << endl;
	}
	~Chulsoo() {
		cout << "Chulsoo::Chulsoo() �Ҹ���" << endl;
	}
	void write() {
		cout << "å�� �� ����" << endl;
	}
};

class Younghee : public virtual Person {
public:
	Younghee() : Person() {
		cout << "Younghee::Younghee() ������" << endl;
	}
	~Younghee() {
		cout << "Younghee::Younghee() �Ҹ���" << endl;
	}
	void write() {
		cout << "å�� �� ����" << endl;
	}
};

class Youngchul : public Chulsoo, public Younghee {
public :
	Youngchul() : Chulsoo(), Younghee() {
		cout << "Youngchul::Youngchul() ������" << endl;
	 }
	~Youngchul() {
		cout << " Youngchul::~Youngchul() �Ҹ���" << endl;
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