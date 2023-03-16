#include<iostream>

int main(void) {
	
	using namespace std; // 이름공간 (자주 사용하진 않음, std의 중복 사용을 피하기 위해서 사용)

	// std::cout -> 출력을 위한 객체
	// << -> 출력 연산자
	// std::endl -> 개행(줄바꿈) 객체
	int a = 2023;
	cout << "Hello World " << a << endl; 

	return 0;
}