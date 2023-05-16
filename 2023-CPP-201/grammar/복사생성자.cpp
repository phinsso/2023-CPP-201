#include<iostream>
#include<string.h>

using namespace std;

class Character {
public:
	// 일반 생성자(깊은 복사)
	Character(const char* str)
	{
		str_ = new char[strlen(str) + 1]; // 매개변수로 넘겨받는 str의 값 + 1 (널문자 들어갈 공간)만큼 배열을 잡는다
		strcpy(str_, str); // 매개변수 str의 내용을 멤버변수 str_에 복사
		cout << "일반생성자 호출" << endl;
	}


	// 복사생성자(얕은 복사로 인하여 문제점이 발생)
	Character(const Character& c) : str_(c.str_)
	{
		cout << "복사생성자 호출" << endl;
	}


	// 소멸자
	~Character() {
		delete[] str_; // str_ 배열을 동적할당 해제
		cout << "소멸자 호출" << endl;
	}

private:
	char* str_;

};

int main(void) {

	Character c1 = Character("abc"); // 일반생성자 호출 
	Character c2 = c1; // 복사생성자 호출

	return 0;
}