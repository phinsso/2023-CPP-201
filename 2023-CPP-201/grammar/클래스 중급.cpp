#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class MString {
public:
	//생성자 (constructor)
	// 객체가 생성될 때 호출되는 함수 (메모리에 할당될 때)
	// 클래스 이름과 같고, 반환형이 없다
	MString(const char* str)
	{ // 포인터로 사용하려면 const 붙여야 함
		// 필요한 길이만큼 문자열 동적할당
		unsigned int str_length = strlen(str);
		c_str_ = new char[str_length + 1]; // null 문자 공간 만들어줌 => + 1
		strcpy(c_str_, str);
		cout << "MString 생성자 호출 완료" << endl;
	}

	// 복사생성자 (별도로 정의하지 않으면 아래와 같은 복사생성자를 컴파일러가 만들어냄)
	MString(const MString& rhs)
		: size_(rhs.size_), c_str_(rhs.c_str_) // 각 필드에 매개변수 값 대입
	{
	}

	// 소멸자 (destructor)
	// 객체가 소멸될 때 호출되는 함수 (메모리에 해제될 때)
	// ~클래스이름, 반환형과 매개변수가 없다
	~MString()
	{
		// 생성자에서 동적할당한 공간을 해제
		delete[] c_str_;
		cout << "MString 소멸자 호출 완료" << endl;
	}

	unsigned int size() { return size_; } //getter
	char* c_str() { return c_str_; } //getter

private:
	unsigned int size_; // 문자열의 길이
	char* c_str_;		// 문자열을 가리키는 주소
};

int main(void) {

	// 일반적인 생성자 호출
	MString str1 = MString("Aitai");

	// 복사생성자 호출
	MString str2 = str1;
	

	return 0;
}