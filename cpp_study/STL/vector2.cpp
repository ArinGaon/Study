#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v(6, 1); // 1로 초기화된 6개의 원소를 가진 벡터 v를 생성
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	v.assign(4, 3); // assign()를 통해 벡터 v를 3으로 초기화된 4개의 원소를 가지도록 변경
				    // size는 4로 줄어들었지만 v의 capacity는 여전히 6인 상태
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	v[2] = 7;
	for (vector<int>::iterator it = v.begin() + 3; it != v.end(); it++)
		*it = 9;

	v.push_back(10);
	v.push_back(20);
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	v.push_back(30); // v의 size가 6에서 7로 늘어나면서 capacity는 6에서 12로 증가됨
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	v.resize(17); // resize()를 통해 capacity와 size가 모두 17로 변경
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	return 0;
}