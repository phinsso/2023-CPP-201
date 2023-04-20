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

	// new로 동적할당한 공간은 반드시 delete로 해제시켜야 함
	// 만약 그러지 않으면 메모리가 누수된다
	MString* str = new MString("Aitai 2-1");

	cout << str->c_str() << endl;

	// str에 대한 delete는 진행되었으나, str->c_str에 대한 delete가 진행되지 않음
	// TODO: 이를 delete 해주는 소멸자 구현하기
	delete str;
	

	return 0;
}