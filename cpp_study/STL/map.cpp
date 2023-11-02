// 연관 컨테이너는 크게 map과 set으로 구분되며 map, multimap, set, multiset의 네가지가 있음
// 연관 컨테이너는 이진트리로 구성됨.
// map 컨테이너는 key-value의 쌍으로 구성되어 있음.

#include <iostream>
#include <map>

using namespace std;

int main() {
	map<string, int> m; // key-value를 string-int형으로 정의하였음

	m.insert(make_pair("A", 10));
	m.insert(make_pair("B", 20));
	m.insert(make_pair("C", 30));
	m.insert(make_pair("D", 40));
	m.insert(make_pair("E", 50));
	m["F"] = 100;

	for (auto i = m.begin(); i != m.end(); ++i) {
		cout << "[" << i->first << " " << i->second << "]";
	}
	cout << endl;

	auto i = m.find("A"); // key가 "A"인 map을 찾는 함수
	cout << i->second;

	return 0;
}