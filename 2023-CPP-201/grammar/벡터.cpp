#include <iostream>
#include <vector>

using namespace std;

// vector
// 동적배열 (가변배열, size 변화 가능)
// 연속된 메모리 공간에 위치 (전통적인 배열도 가지고 있는 특징)
// 임의접근 가능 (전통적인 배열도 가지고 있는 특징)

int main(void) {
	// 전통적인 배열은 크기가 고정되어 있으나,
	// 벡터는 크기가 자유롭게 변할 수 있는 동적배열이다.
	vector<int> arr;
	arr.reserve(4); // 벡터의 크기를 4로 한다
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);

	// 4개가 꽉 찬 공간에 데이터 하나를 더 넣어보자
	arr.push_back(50);
	
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}