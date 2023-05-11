#include<iostream>

using namespace std;

int main(void) {

	// ptr1은 int 3개짜리 배열을 동적할당시킨 후 가리킨다
	int* ptr1 = new int[3];
	ptr1[0] = 0, ptr1[1] = 10, ptr1[2] = 20;

	// ptr2는 별도의 공간을 동적할당 한 후, ptr1이 가리키는 값들을 복사한다 => 깊은복사(deep copy)
	int* ptr2 = new int[3];
	for (int i = 0; i < 3; i++) {
		ptr2[i] = ptr1[i];
	}

	// 깊은 복사를 하면 고유의 공간을 가지므로, ptr2[1]은 100으로 바뀌지 않는다.
	ptr1[1] = 100;

	for (int i = 0; i < 3; i++) {
		cout << ptr1[i] << " " << ptr2[i] << endl;
	}

	delete[] ptr1;
	delete[] ptr2;
	// 얕은 복사인 경우, ptr2는 ptr1과 같은 메모리를 가리키기 때문에 지운 데이터를 또 지울 수 없어 에러가 났지만
	// 깊은 복사의 경우, ptr1과 ptr2는 별도의 공간이기 때문에 에러가 나지 않고 동적할당이 해제가 된다.

	return 0;
}