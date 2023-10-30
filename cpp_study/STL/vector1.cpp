// vector�� Ư�� ���� ���� �������ϴ� �����
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v(6, 1); // ũ�Ⱑ 6�� ���͸� 1�� �ʱ�ȭ
	for (auto i = 0; i < v.size(); i++) // auto�� ���������� �ڵ����� ���������� ���� ���⼭�� vector<int>::size_type���� ��ȯ�� ������ ����
		cout << v[i] << " ";
	cout << endl;

	v.assign(4, 3); // assign()�Լ��� �̿��Ͽ� ���� ���� ������ -> ������ ������ 4���� �پ������ vector�� �Ҵ���� �޸��� ũ�Ⱑ �پ������ ����
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	v[2] = 7; // v[2]�� ���� ���������� �Է��ϴ� ���
	for (auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	// vector<int>::iterator it = vector�� �ּҰ��̶�� �� �� ����
	for (vector<int>::iterator it = v.begin() + 3; it != v.end(); it++) // 4��° ���Һ��� ���� 9�� ������, 13���� assign()�Լ��� ���� �������� ���� ������ ������ 4���̱⿡ 4��° ������ ���� 9�� ������
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