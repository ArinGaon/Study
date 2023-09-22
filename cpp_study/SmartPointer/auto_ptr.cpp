// 스마트 포인터 auto_ptr 사용 
/* 프로그램이 커질 수록 내부 멤버들이 많아지고 이를 동적 메모리로 할당해서 관리하려면 new,delete를 항상 쌍으로 사용해야함
	스마트 포인터 auto_ptr을 사용한 동적 메모리 할당에서는 개발자가 delete를 따로 하지 않아도 소멸자를 호출하면서 동적할당을 자동으로 해제
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
	// Chulsoo* chulsooPtr1 = (Chulsoo*)malloc(sizeof(Chulsoo)); // chulsooPt1 포인터 변수를 선언하며 동적할당
	// chulsooPtr1->setAge(32);
	// chulsooPtr1->introduce();
	
	//// 기존 동적할당과 비교하기 위해 주석 처리
	auto_ptr<Chulsoo> chulsooSmptr(new Chulsoo(32));
	chulsooSmptr->introduce();

	//free(chulsooPtr1); // 할당 해제
	return 0;
}

void Chulsoo::introduce() {
	cout << "철수 나이 : " << age << endl;
}

// auto_ptr은 포인터 변수가 NULL값을 가리키게 하는 문제가 있어 (이는 컴파일 에러에 잡히지 않고 코드 실행 후 런타임 에러를 초래) 권장하지 않음