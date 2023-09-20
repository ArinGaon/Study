//동적 메모리 할당(new)과 해제(delete)
#include <iostream>

using namespace std;

class Chulsoo {
private:
	char * name;
	int * age;
public:
	Chulsoo(char * name, int age) {
		this->name = new char[strlen(name) + 1]; // name 동적메모리 할당
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = new int; // age 동적메모리 할당
		*this->age = age;
		cout << "Chulsoo::Chulsoo(name) 생성자 완료" << endl;
	}
	~Chulsoo() {
		delete[] name; // 동적 메모리 해제
		delete age;
		cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
	}
	void introduce();
};

int main() {
	Chulsoo chulsoo((char*)"철수", 32); // 책에는 chulsoo("철수", 32) 로 되어있지만, 컴파일 에러가 발생하여 원인을 보니 const char*형식으로 넘겨줘야한대서 철수앞에 (char*) 추가
	chulsoo.introduce();
	return 0;
}

void Chulsoo::introduce() {
	cout << "이름 : " << name << endl;
	cout << "나이 : " << *age << endl;
}
