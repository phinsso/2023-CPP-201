#include<iostream>

using namespace std;

int main(void) {
	
	int a = 30;    //a: 30

	int* pa = &a;  //pa: a의 주소값
	*pa = 100;     //pa가 기리키는 대상(a)의 값을 바꾸겠다는 뜻

	cout << "a의 값은 " << a << endl;

	

	return 0;
}