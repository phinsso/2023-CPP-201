//C++
#include<iostream>
#include<string>

using namespace std;

// 여러 데이터들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 단어의 첫 글자를 대문자로 한다
struct Student {

	string name;
	// 문자열로 하지 않는 이유: 성능 (일반적으로 문자열은 정수 데이터보다 많은 메모리 공간을 요구하며, 정수는 비교연산이 한 번에 가능하나 문자열은 글자수만큼 반복하여 비교하기 때문
	int stuId;
	int age;
	// 0: 남자, 1: 여자
	int sex; // 유지보수를 위해 열거형(enum) 형으로 하는 것을 추천
	string department;

};

int main(void) {

	struct Student stu1;
	stu1.name = "나소정";
	stu1.stuId = 2106;
	stu1.age = 18;
	stu1.sex = 1;
	stu1.department = "뉴미디어소프트웨어과";

	cout << stu1.name << " " << stu1.stuId << " " << stu1.age << " " << stu1.sex << " " << stu1.major << endl;

	return 0;
}