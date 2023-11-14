﻿#include<iostream>
#include<string>

using namespace std;

class Champ {
public:
	// 함수의 선언
	Champ(const string& name);
	static int get_cnt();
private:
	static int cnt_;
};

// 함수를 바깥에서 정의할 때는 멤버함수나 멤버변수 이름 앞에 클래스 이름:: 을 붙인다
Champ::Champ(const string& name) {
	++cnt_;
}

int Champ::get_cnt() {
	return cnt_;
}

// static 멤버변수는 무조건 바깥에서 정의 (const 제외)
int Champ::cnt_ = 0;

int main(void) {
	Champ* a = new Champ("아지르");
	Champ* a = new Champ("승호");
	// Champ::cnt_의 값은 2
	// cnt_ 변수는 모두가 공유하기 때문에 1개만 있고
	// Champ형 객체는 2개가 있다

	// 객체 생성 없이도 static 멤버함수 호출 가능
	cout << Champ::get_cnt() << endl;
	// cout << a->get_cnt() << endl;
	// cout << b->get_cnt() << endl;
}