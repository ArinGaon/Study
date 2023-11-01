// forward_list는 list와 다르게 단일 연결 리스트로 구성된 컨테이너
// push_back함수는 지원되지 않고 추가되는 원소는 front에만 추가할 수 있음 
// before_begin()이라는 특별한 멤버함수도 가지고 있음 -> 시작 원소 바로 앞 위치를 나타냄
#include <iostream>
#include <forward_list>

using namespace std;

int main() {
	forward_list<int> fl;
	forward_list<int> fl2 = { 1,2,3,4 };

	fl.push_front(10);
	fl.push_front(20);
	fl.push_front(30);
	fl.push_front(40);

	for (auto i = fl.begin(); i != fl.end(); i++)
		cout << *i << " ";
	cout << endl;

	for (auto i = fl2.begin(); i != fl2.end(); i++)
		cout << *i << " ";
	cout << endl;

	for (auto i = fl.begin(); i != fl.end(); i++) {
		if (*i == 30) {
			fl.splice_after(i, fl2); // *i의 값이 30이 되는 지점 다음 값부터 fl2의 값을 삽입
			break;
		}
	}

	for (auto i = fl.begin(); i != fl.end(); i++)
		cout << *i << " ";
	cout << endl;

	forward_list<int> fl3 = { 100,200,300,400 };
	auto p = fl.before_begin(); // p는 fl 리스트의 시작 원소보다 바로 앞쪽의 위치를 나타냄
	fl.splice_after(p, fl3);
	for (auto i = fl.begin(); i != fl.end(); i++)
		cout << *i << " ";
	cout << endl;

	return 0;
}