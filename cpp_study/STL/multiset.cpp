// multiset은 set의 기능에 추가로 key값 중복을 허용하는 연관 컨테이너

#include <iostream>
#include <set>

using namespace std;

int main() {
	multiset<int> ms;
	multiset<int>::iterator ms_iter;

	ms.insert(10);
	ms.insert(30);
	ms.insert(60);
	ms.insert(20);
	ms.insert(50);
	ms.insert(40);
	ms_iter = ms.insert(40);

	for (auto i = ms.begin(); i != ms.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	cout << "40의 개수 : " << ms.count(40) << endl;  // count() : key값의 갯수를 셈
	auto f = ms.find(40);
	if (f != ms.end()) {
		cout << *f << endl;
	}

	return 0;
}