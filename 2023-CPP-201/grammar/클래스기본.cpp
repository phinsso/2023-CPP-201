//C++
#include<iostream>
#include<string>

using namespace std;

// 여러 데이터들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 단어의 첫 글자를 대문자로 한다
// class는 디폴트가 private (struct는 디폴트가 public)

struct Actor {
	string name;
	string dialog;
};


class Student {

public:
	//생성자 (constructor): 객체가 생성될 때 호출되는 함수
	// 생성자를 정의하지 않으면 default로 매개변수가 없는 생성자가 정의된다.

	Student() {
		name = "나소정";
		stuId = 2106;
		age = 18;
		sex = 1;
		department = "뉴미디어소프트웨어과";
	}

	Student(string name, int stuId, int age, int sex, string department) { // 매개변수 이름을 다르게 하면 this 키워드 사용 안 해도 됨
		this->name = name;
		this->stuId = stuId;
		this->age = age;
		this->sex = sex;
		this->department = department;
	}

	void print(void)
	{ // class는 멤버변수를 가질 수 있다
		cout << "이름: " << name << endl;
		cout << "학번: " << stuId << endl;
		cout << "나이: " << age << endl;
		cout << "성별: " << sex << endl; // 0: 남자, 1: 여자
		cout << "학과: " << department << endl << endl;
	}

private:
	string name;
	// 문자열로 하지 않는 이유: 성능 (일반적으로 문자열은 정수 데이터보다 많은 메모리 공간을 요구하며, 정수는 비교연산이 한 번에 가능하나 문자열은 글자수만큼 반복하여 비교하기 때문
	int stuId;
	int age;
	// 0: 남자, 1: 여자
	int sex; // 유지보수를 위해 열거형(enum) 형으로 하는 것을 추천
	string department;

};

int main(void) {

	Student stu1 = Student(); // == Student stu1;
	stu1.print();

	Student stu2 = Student("김메론소다", 1207, 17, 1, "뉴미디어웹솔루션과");
	stu2.print();

	struct Actor SHLee;
	SHLee.name = "이수혁";
	SHLee.dialog = "너무 잘생겼음";

	struct Actor* ptr = &SHLee;

	//ptr->name과 (*ptr).name 은 같은 결과
	cout << "이름: " << ptr->name << endl;
	cout << "대사: " << (*ptr).dialog << endl;

	return 0;
}