// multimap������ key ���� �ߺ��� ���� 
// map ������ find()�Լ��� �̿��Ͽ� Ư�� key ���� ������ map�� ã�� �� ������
// multipmap������ lower_bound(), upper_bound() �Ǵ� equal_range()��� ����Լ��� ����Ͽ� Ư�� Ű ���� ������ multimap�� ã�� �� �ִ�.

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
	// C�� key���� ������ multimap 3���� ����Ǿ�����.

	for (auto i = mm.begin(); i != mm.end(); ++i) {
		cout << "[" << i->first << " " << i->second << "] ";
	}
	cout << endl;
	/*
	upper_bound�Լ��� ��� �����̳��� ������ ���� �� ���� ���Һ��� ū ���� ���� ���ʿ� �ִ� ������ iterator���� �����Ѵ�.
	lower_bound�Լ��� ��� ������ ���� �� ���� ���ҿ� ���ų� ū �� �� ���� ���ʿ� �ִ� ������ iterator���� �����Ѵ�.
	*/
	auto lo_bo = mm.lower_bound("C");
	auto up_bo = mm.upper_bound("C");
	cout << "key C�� value �� : ";
	for (auto i = lo_bo; i != up_bo; ++i) {
		cout << i->second << " ";
	}
	cout << endl;

	auto eq_ra = mm.equal_range("C");
	cout << "(�� �ٸ� ���)key C�� value�� : ";
	for (auto i = eq_ra.first; i != eq_ra.second; ++i) {
		cout << i->second << " ";
	}
	cout << endl;

	return 0;
}