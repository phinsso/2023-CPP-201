#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class MString {
public:
	//생성자
	MString(const char* str) { // 포인터로 사용하려면 const 붙여야 함
		// 필요한 길이만큼 문자열 동적할당
		unsigned int str_length = strlen(str);
		c_str_ = new char[str_length + 1]; // null 문자 공간 만들어줌 => + 1
		strcpy(c_str_, str);
	} 

	unsigned int size() { return size_; } //getter
	char* c_str() { return c_str_; } //getter

private:
	unsigned int size_; // 문자열의 길이
	char* c_str_;		// 문자열을 가리키는 주소
};

int main(void) {

	MString str = MString("takoyaki tabetai");
	cout << str.c_str() << endl;
	return 0;
}