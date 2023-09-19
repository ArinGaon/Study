// static ��� ����
#include <iostream>

class Chulsoo {
private: // private ���� �����ڷ� static ����
	int age;
	static int chulsooPrivateCounter;
protected: // protected ���� �����ڷ� static ���� ����
	static int chulsooProtectedCounter;
public: // public ���� �����ڷ� static ���� ����
	static int chulsooPublicCounter;
	Chulsoo(int age) : age(age) {
		// ��ü ���� �ø��� ������ ������ �����ڿ� �����ϴ� �ڵ忡 ���������ڸ� ����
		chulsooPrivateCounter++;
		chulsooProtectedCounter++;
		chulsooPublicCounter++;
		
		std::cout << "Chulsoo::chulsoo(age) �����ڷ� ���������" << chulsooPrivateCounter << "(private)��° ��ü ���� �Ϸ�" << std::endl;
		std::cout << "Chulsoo::chulsoo(age) �����ڷ� ���������" << chulsooProtectedCounter << "(protected)��° ��ü ���� �Ϸ�" << std::endl;
		std::cout << "Chulsoo::chulsoo(age) �����ڷ� ���������" << chulsooPublicCounter << "(public)��° ��ü ���� �Ϸ�" << std::endl;
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
		// �� �ּ�ó���� ģ������ �ּ��� Ǯ�� chulsooPublicCounter������ �� �ּ�ó���� ������ ����
		Chulsoo::chulsooPublicCounter++;
		std::cout << "Younghee::Younghee(age) �����ڷ� ��������� " << Chulsoo::chulsooPublicCounter << "��° ��ü ���� �Ϸ�" << std::endl;
	}
};

int main() {
	// ��ü 4�� ����
	Chulsoo chulsoo1(32);
	Chulsoo chulsoo2(32);
	Younghee younghee1(32);
	Younghee younghee2(32);
	return 0;
}