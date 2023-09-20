// 스마트 포인터 unique_ptr 사용 
/* 
	unique_ptr을 사용하면 auto_ptr과 다르게 런타임에러가 발생하지 않고 컴파일러가 오류를 잡아줘서 오류발생을 막아줌
	아래 소스는 컴파일 에러가 발생하는 소스
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
	unique_ptr<Chulsoo> chulsooSmptr1(new Chulsoo(32));
	chulsooSmptr1->introduce();
	cout << "auto_ptr<Chulsoo> 타입 간 생성자 호출 후" << endl;
	unique_ptr<Chulsoo> chulsooSmptr2 = chulsooSmptr1;
	chulsooSmptr1->introduce();
	chulsooSmptr2->introduce();

	return 0;
}

void Chulsoo::introduce() {
	cout << "철수 나이 : " << age << endl;
}

