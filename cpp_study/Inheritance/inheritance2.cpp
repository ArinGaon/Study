#include <iostream>
using namespace std;

#define NAME_LEN 20

class Person {
private:
	int agePrivate;
protected:
	int ageProtected;
public:
	int agePublic;

	Person(int age) : agePrivate(age), ageProtected(age), agePublic(age) {}
	~Person() {}
};

class Chulsoo :public Person {
private:
	int numOfBooks;
public:
	Chulsoo(int age, int numOfBooks) : Person(age), numOfBooks(numOfBooks){}
	~Chulsoo() {}

	void introduce() {
		// cout << "agePrivate : " << agePrivate << endl; <- 이 부분 주석을 해제하면 접근할 수 없다는 오류가 발생
		cout << "ageProtected : " << ageProtected << endl;
		cout << "agePublic : " << agePublic << endl;
		// private을 제외한 접근지정자에는 모두 접근할 수 있음
	}
};

int main() {
	Chulsoo chulsoo(32, 3);
	chulsoo.introduce();
	return 0;
}