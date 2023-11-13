#include<iostream>
#include<string>

using namespace std;

class Champ {
public:
	// 함수의 선언
	Champ(const string& name);
private:
	static int cnt_;
};

// 함수를 바깥에서 정의할 때는 멤버함수나 멤버변수 이름 앞에 클래스 이름:: 을 붙인다
Champ::Champ(const string& name) {
	++cnt_;
}

int Champ::cnt_ = 0;

int main(void) {
	Champ* a = new Champ("아지르");
	Champ* a = new Champ("승호");
}