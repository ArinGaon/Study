// static 멤버 변수
#include <iostream>

class Chulsoo {
private: // private 접근 지정자로 static 변수
	int age;
	static int chulsooPrivateCounter;
protected: // protected 접근 지정자로 static 변수 선언
	static int chulsooProtectedCounter;
public: // public 접근 지정자로 static 변수 선언
	static int chulsooPublicCounter;
	Chulsoo(int age) : age(age) {
		// 객체 생성 시마다 개수를 세고자 생성자에 진입하는 코드에 증가연산자를 적용
		chulsooPrivateCounter++;
		chulsooProtectedCounter++;
		chulsooPublicCounter++;
		
		std::cout << "Chulsoo::chulsoo(age) 생성자로 만들어지는" << chulsooPrivateCounter << "(private)번째 객체 생성 완료" << std::endl;
		std::cout << "Chulsoo::chulsoo(age) 생성자로 만들어지는" << chulsooProtectedCounter << "(protected)번째 객체 생성 완료" << std::endl;
		std::cout << "Chulsoo::chulsoo(age) 생성자로 만들어지는" << chulsooPublicCounter << "(public)번째 객체 생성 완료" << std::endl;
	}
};
int Chulsoo::chulsooPrivateCounter = 0;
int Chulsoo::chulsooProtectedCounter = 0;
int Chulsoo::chulsooPublicCounter = 0;

class Younghee {
private:
	int age;
public:
	Younghee(int age) : age(age) {
		//Chulsoo::chulsooPrivateCouter++;
		//Chulsoo::chulooProtectedCounter++;
		// 위 주석처리한 친구들을 주석을 풀면 chulsooPublicCounter변수를 위 주석처리한 변수로 변경
		Chulsoo::chulsooPublicCounter++;
		std::cout << "Younghee::Younghee(age) 생성자로 만들어지는 " << Chulsoo::chulsooPublicCounter << "번째 객체 생성 완료" << std::endl;
	}
};

int main() {
	// 객체 4개 생성
	Chulsoo chulsoo1(32);
	Chulsoo chulsoo2(32);
	Younghee younghee1(32);
	Younghee younghee2(32);
	return 0;
}