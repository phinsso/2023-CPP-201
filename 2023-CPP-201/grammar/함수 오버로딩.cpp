#include<iostream>

using namespace std;

//함수 오버로딩 -> 함수 이름을 간결하게 할 수 있음
//함수 이름은 같지만, 매개변수가 다르다
int sum(int a, int b)
{
	return a + b;
}

float sum(float a, float b) {
	return a + b;
}

int main(void) {

	cout << sum(1, 2) << endl;
	cout << sum(1.1f, 2.2f) << endl;
	return 0;
}