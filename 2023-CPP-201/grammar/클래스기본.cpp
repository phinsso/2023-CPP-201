//C++
#include<iostream>
#include<string>

using namespace std;

// 여러 데이터들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 단어의 첫 글자를 대문자로 한다
// class는 디폴트가 private (struct는 디폴트가 public)


class Student {

public:
	// 생성자 (constructor): 객체가 생성될 때 호출되는 함수
	// 생성자를 정의하지 않으면 default로 매개변수가 없는 생성자가 정의된다.
	// 생성자 함수의 이름은 클래스명과 같다
	// 생성자는 반환형을 쓰지 않는다

	Student() {}

	Student(string name, int stuId, int age, int sex, string department)
		: name(name), stuId(stuId), age(age), sex(sex), department(department) // 멤버변수 초기화
	{
	}

	void print(void)
	{ // class는 멤버변수를 가질 수 있다
		cout << "이름: " << name << endl;
		cout << "학번: " << stuId << endl;
		cout << "나이: " << age << endl;
		cout << "성별: " << sex << endl; // 0: 남자, 1: 여자
		cout << "학과: " << department << endl << endl;
	}

	void set_name(string name) { this->name = name; }
	void set_stuId(int stuId) { this->stuId = stuId; }
	void set_age(int age) { this->age = age; }
	void set_sex(int sex) { this->sex = sex; }
	void set_department(string department) { this->department = department; }


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
	
	// 정적할당: 메모리의 크기가 컴파일할 때 결정됨, stack 영역
	//Student stu1 = Student("김메론소다", 1207, 17, 1, "뉴미디어웹솔루션과");
	//stu1.print();

	/*Student stu3[2];
	for (int i = 0; i < 2; i++) {
		stu3[i].print();
	}*/

	// 동적할당: 메모리의 크기가 실행할 때 (runtime)에 결정됨, heap 영역
	// c++의 동적할당은 반드시 delete로 해제해야 메모리 누수를 막을 수 있음
	
	//Student* stu2 = new Student("이수혁", 3100, 31, 0, "방송연예과"); // 포인터로 접근하기 때문에 실제 데이터에 접근하는 것이 아님
	//stu2->print(); // (포인터)단일 객체는 멤버를 -> 로 접근 (실제 데이터에 접근하기 위해 -> 사용)
	//delete stu2; // 동적할당 해제

	Student* stu4 = new Student[2];
	stu4[0].set_age(18);
	stu4[0].set_name("나소정");
	stu4[0].set_sex(1);
	stu4[0].set_stuId(2106);
	stu4[0].set_department("뉴미디어소프트웨어과");

	stu4[1].set_age(18);
	stu4[1].set_name("이수혁");
	stu4[1].set_stuId(2119);
	stu4[1].set_sex(0);
	stu4[1].set_department("뉴미디어소프트웨어과");

	for (int i = 0; i < 2; i++) {
		stu4[i].print(); // (포인터)배열의 요소에 해당하는 객체는 멤버를 .으로 접근
	}
	delete[] stu4;

	
	return 0;
}