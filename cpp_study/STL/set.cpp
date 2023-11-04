// set 컨테이너는 map보다 단순한 연관 컨테이너이다.
// set 컨테이너는 map과 다르게 key-value로 이루어지지 않고 key값만 을 저장하고 있다.

#include <iostream>
#include <set>

using namespace std;

int main() {
	set <int> s;
	pair<set<int>::iterator, bool> pr;

	s.insert(10);
	s.insert(30);
	s.insert(60);
	s.insert(20);
	s.insert(50);
	pr = s.insert(40);

	for (auto i = s.begin(); i != s.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	s.insert(pr.first, 55);

	for (auto i = s.begin(); i != s.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	auto f = s.find(55);
	if (f != s.end()) {
		cout << *f << endl;
	}

	return 0;
}