#include <iostream>
#include <string>

using namespace std;

// 자바의 제네릭과 비슷함
template <typename T>
T sum(T a, T b) {
	return a + b;
}

int main(void) {

	cout << sum<int>(1, 2) << endl;
	cout << sum<float>(1.f, 2.f) << endl;
	cout << sum<string>("1", "2") << endl;

	return 0;
}