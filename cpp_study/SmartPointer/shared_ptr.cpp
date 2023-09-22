// 스마트 포인터 shared_ptr 사용 
/* 
	하나의 동적 객체를 여러 스마트 포인터로 가리키길 원할 때 사용하는 스마트 포인터
*/
#include <iostream>
#include <memory>

using namespace std;

class Chulsoo {
private:
	int age;
public:
	Chulsoo(int age) : age(age) {
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}
	~Chulsoo() {
		cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
	}
	void setAge(int age) {
		this->age = age;
	}
	void introduce();
};

int main() {
	shared_ptr<Chulsoo> chulsooSmptr1(new Chulsoo(32));
	chulsooSmptr1->introduce();
	cout << "auto_ptr<Chulsoo> 타입 간 복사 생성자 호출 후" << endl;
	shared_ptr<Chulsoo> chulsooSmptr2 = chulsooSmptr1;
	chulsooSmptr1->introduce();
	chulsooSmptr2->introduce();

	return 0;
}

void Chulsoo::introduce() {
	cout << "철수 나이 : " << age << endl;
}

