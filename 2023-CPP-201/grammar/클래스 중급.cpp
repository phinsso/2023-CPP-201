#include<iostream>

using namespace std;

class MString {
public:
	//생성자
	MString(const char* str) { // 포인터로 사용하려면 const 붙여야 함
		c_str_ = str;
	}

	unsigned int size() { return size_; } //getter
	const char* c_str() { return c_str_; } //getter

private:
	unsigned int size_; // 문자열의 길이
	const char* c_str_;		// 문자열을 가리키는 주소
};

int main(void) {

	MString str = MString("takoyaki tabetai");
	cout << str.c_str() << endl;
	return 0;
}