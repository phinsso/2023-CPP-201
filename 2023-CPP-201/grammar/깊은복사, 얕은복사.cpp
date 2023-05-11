#include<iostream>

using namespace std;

int main(void) {

	// ptr1은 int 3개짜리 개병를 동적할당시킨 후 가리킨다
	int* ptr1 = new int[3]; // 동적할당
	ptr1[0] = 0, ptr1[1] = 10, ptr1[2] = 20;

	// ptr2는 별도의 동적할당을 하지 않고, ptr1의 주소값만 복사 => 얕은복사(shallow copy)
	int* ptr2 = ptr1;

	// 얕은 복사를 하면 원본 데이터에 종속된다.
	// 즉, ptr2[1]도 100으로 변경된다.
	ptr1[1] = 100;

	for (int i = 0; i < 3; i++) {
		cout << ptr1[i] << " " << ptr2[i] << endl;
	}

	return 0;
}