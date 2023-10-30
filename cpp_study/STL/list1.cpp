/*
	list는 이중 연결 시트르오 이루어진 순차컨테이너
	vector는 메모리상에 연속적으로, deque도 중간중간 연속적이지 않은 구간이 있을 수 있으나,
	블록 단위로는 연속적인 메모리에 위치하고 있었던 것에 비해
	list는 메모리 상에 연속적으로 위치하지 않음

	단, 논리적으로는 연속적인 데이터를 저장
*/
#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> lt;

	// vector나 deque와 같이 push_back과 push_front를 사용할 수 있음
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_front(-10);
	lt.push_front(-20);
	lt.push_front(-30);

	for (auto i = lt.begin(); i != lt.end(); i++)
		cout << *i << " ";
	cout << endl;
	
	// list 컨테이너는 ++p와 같이 차례대로 원소를 이동해야함 (p+n)과 같은 이동 불가능)
	for (auto p = lt.begin(); p != lt.end(); p++) {
		if (*p == 10) {
			lt.insert(p, 0);
			break;
		}

	}

	for (auto i = lt.begin(); i != lt.end(); i++)
		cout << *i << " ";
	cout << endl;	

	return 0;
}