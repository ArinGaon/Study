//동적 메모리 할당(new)과 해제(delete)
#include <iostream>

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
	Chulsoo* chulsooPtr1 = (Chulsoo*)malloc(sizeof(Chulsoo)); // chulsooPt1 포인터 변수를 선언하며 동적할당
	chulsooPtr1->setAge(32);
	chulsooPtr1->introduce();

	free(chulsooPtr1); // 할당 해제
	return 0;
}

void Chulsoo::introduce() {
	cout << "철수 나이 : " << age << endl;
}
// new & delete 를 사용하는 경우

/*
int main(){
	Chulsoo * chulsooPtr1 = new Chulsoo(32);
	chulsooPtr1->introduce();

	delete chulsooPtr1;
	return 0;
*/ // new, delete 연산자를 통해 일반 자료형 뿐 아니라 클래스 객체도 동적 메모리에 할당하고 해제 가능