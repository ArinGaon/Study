// array는 동적 할당을 지원하지 않는 컨테이너
// 최초 생성시에 지정한 원소의 갯수만큼 메모리를 점유

#include <iostream>
#include <array>

using namespace std;

int main() {
	array<int, 10> ar;
	ar = { 1,2,3 };

	for (auto i = 0; i < ar.size(); i++)
		cout << ar.at(i) << " ";
	cout << endl;

	ar.fill(5); // fill(i) 함수는 ar객체의 모든 원소를 i로 채우는 함수

	for (auto i = 0; i < ar.size(); i++)
		cout << ar.at(1) << " ";

	return 0;
}