#include <iostream>
#include <vector>

using namespace std;

template <typename T=int, int init=3> // int init = 3 과 같이 디폴트 값을 설정할 때에는 처음 템플릿 파라미터를 정의한 곳에서 한 번만 해야한다. (어길 경우 컴파일 에러)
class MyArray {
private:
	vector<T> list;
public:
	MyArray() {
		for (int i = 0; i < init; ++i)
			list.push_back(i);
	}
	void add_list(T const&);
	void delete_last_list(void);
	void show_list(void);
};

template <typename T, int init>
void MyArray<T, init>::add_list(T const& element) {
	list.push_back(element);
}

template <typename T, int init>
void MyArray<T, init>::delete_last_list(void) {
	list.pop_back();
}

template <typename T, int init>
void MyArray<T, init>::show_list() {
	cout << "[MyArray list look up]" << endl;
	for (typename vector<T>::iterator i = list.begin(); i != list.end(); ++i)
		cout << *i << endl;
}

int main() {
	MyArray<> array1;
	array1.add_list(1.1);
	array1.add_list(2.2);
	array1.add_list(3.3);
	array1.add_list(4.4);
	array1.add_list(5.5);

	array1.show_list();
	
	array1.delete_last_list();
	array1.delete_last_list();

	array1.show_list();

	MyArray<> array2; // 템플릿 파라미터 형을 명시하지 않았기에 디폴트로 지정한 int형으로 데이터가 출력
	// 디폴트 템플릿 파라미터를 정의하였더라도 꺽쇠(<>)는 무조건 명시하여야함
	array2.add_list(1.1);
	array2.add_list(2.2);
	array2.add_list(3.3);
	array2.add_list(4.4);
	array2.add_list(5.5);

	array2.show_list();

	array2.delete_last_list();
	array2.delete_last_list();

	array2.show_list();

	return 0;
}