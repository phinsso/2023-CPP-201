#include<iostream>
using namespace std;

class Person {

public:
	Person(string name, int hakbun) : name_(name), hakbun_(hakbun)
	{
	}

	void Printshow() {
		cout << "이름: " << name_ << "  학번: " << hakbun_ << endl;
	}

	~Person() { cout << "Person 소멸자()" << endl; }

private:
	string name_;
	int hakbun_;
};

class Student : public Person {

public: 
	Student(string name, int hakbun, string university) : Person(name, hakbun), university_(university)
	{
		cout << "대학교: " << university_ << endl;
	}

	~Student() { cout << "Student 소멸자()" << endl; }

private:
	string university_;

};

int main(void) {
	Student* stu = new Student("김미림", 2106, "미림대학교");
	stu->Printshow();
	delete stu;
}