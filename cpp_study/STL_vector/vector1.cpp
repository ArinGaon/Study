// vector의 특정 원소 값을 재지정하는 방법들
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v(6, 1); // 크기가 6인 벡터를 1로 초기화
	for (auto i = 0; i < v.size(); i++) // auto는 데이터형을 자동으로 데이터형을 지정 여기서는 vector<int>::size_type으로 변환될 것으로 기대됨
		cout << v[i] << " ";
	cout << endl;

	v.assign(4, 3); // assign()함수를 이용하여 원소 값을 재지정 -> 원소의 갯수는 4개로 줄어들지만 vector가 할당받은 메모리의 크기가 줄어들지는 않음
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	v[2] = 7; // v[2]의 값을 직관적으로 입력하는 방식
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	// vector<int>::iterator it = vector의 주소값이라고 볼 수 있음
	for (vector<int>::iterator it = v.begin() + 3; it != v.end(); it++) // 4번째 원소부터 값을 9로 재지정, 13행의 assign()함수에 따른 재지정에 따라 원소의 갯수가 4개이기에 4번째 원소의 값만 9로 재지정
		*it = 9;
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	v.push_back(10);
	v.push_back(20);
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	return 0;
}