#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v(6, 1); // 1�� �ʱ�ȭ�� 6���� ���Ҹ� ���� ���� v�� ����
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	v.assign(4, 3); // assign()�� ���� ���� v�� 3���� �ʱ�ȭ�� 4���� ���Ҹ� �������� ����
				    // size�� 4�� �پ������� v�� capacity�� ������ 6�� ����
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

	v.push_back(30); // v�� size�� 6���� 7�� �þ�鼭 capacity�� 6���� 12�� ������
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	v.resize(17); // resize()�� ���� capacity�� size�� ��� 17�� ����
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n\n";

	return 0;
}