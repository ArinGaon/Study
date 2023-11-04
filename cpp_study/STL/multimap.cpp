// multimap에서는 key 값의 중복이 허용됨 
// map 에서는 find()함수를 이용하여 특정 key 값을 가지는 map을 찾을 수 있지만
// multipmap에서는 lower_bound(), upper_bound() 또는 equal_range()라는 멤버함수를 사용하여 특정 키 값을 가지는 multimap을 찾을 수 있다.

#include <iostream>
#include <map>

using namespace std;

int main() {
	multimap<string, int> mm;
	mm.insert(make_pair("A", 10));
	mm.insert(make_pair("B", 20));
	mm.insert(make_pair("C", 30));
	mm.insert(make_pair("D", 40));
	mm.insert(make_pair("E", 50));
	mm.insert(make_pair("C", 100));
	mm.insert(make_pair("C", 200));
	// C의 key값을 가지는 multimap 3개가 선언되어있음.

	for (auto i = mm.begin(); i != mm.end(); ++i) {
		cout << "[" << i->first << " " << i->second << "] ";
	}
	cout << endl;
	/*
	upper_bound함수의 경우 컨테이너의 오른쪽 원소 중 기준 원소보다 큰 값중 가장 왼쪽에 있는 원소의 iterator값을 리턴한다.
	lower_bound함수의 경우 오른쪽 원소 중 기준 원소와 같거나 큰 값 중 가장 왼쪽에 있는 원소의 iterator값을 리턴한다.
	*/
	auto lo_bo = mm.lower_bound("C");
	auto up_bo = mm.upper_bound("C");
	cout << "key C의 value 들 : ";
	for (auto i = lo_bo; i != up_bo; ++i) {
		cout << i->second << " ";
	}
	cout << endl;

	auto eq_ra = mm.equal_range("C");
	cout << "(또 다른 방법)key C의 value들 : ";
	for (auto i = eq_ra.first; i != eq_ra.second; ++i) {
		cout << i->second << " ";
	}
	cout << endl;

	return 0;
}