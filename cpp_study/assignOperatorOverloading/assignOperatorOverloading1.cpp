// 대입 연산자 오버로딩
#include <iostream>

using namespace std;

class Chulsoo {
private:
	int age;
public:
	Chulsoo(const Chulsoo& source) : age(source.age) {
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}
	Chulsoo(int age) : age(age) {
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}
	Chulsoo() {
		cout << "Chulsoo::Chulsoo() 생성자 완료" << endl;
	}
	void introduce();
	~Chulsoo() { // '~' : 소멸자 
		cout << "Chulsoo::Chulsoo() 소멸자 완료" << endl;
	}
};

int main() {
	Chulsoo chulsoo1(32);
	Chulsoo chulsoo2(50);

	chulsoo1.introduce();
	chulsoo2.introduce();
	cout << "==========대입 연산 전==========" << endl;
	chulsoo1 = chulsoo2; // chulsoo1에 chulsoo2 대입
	cout << "==========대입 연산 후==========" << endl;
	chulsoo1.introduce();
	chulsoo2.introduce();
	return 0;
}

void Chulsoo::introduce() {
	cout << "나이 : "<< age << endl;
}

 /*
	operator=()함수를 Chulsoo 클래스 내부에서 정의하지 않았는데도 정상적으로 결과가 출력됨
		이유는 빈 클래스라도 컴파일러가 자동으로 만드는 4개의 함수 중 복사 대입 연산자가 있기 때문
			assignOperatorOverloading2.cpp에서 복사 대입연산자 예제 진행
 */