//C++
#include<iostream>
#include<string>

using namespace std;

class Employee {
private:
	string name_;
	int id_;
	int age_;
	double salary_;

public:

	Employee(){}

	Employee(string name, int id, int age, double salary)
	: name_(name), id_(id), age_(age), salary_(salary)
	{}

	void PrintInfo(void) {
		cout << "이름: " << name_ << endl;
		cout << "사번: " << id_ << endl;
		cout << "나이: " << age_ << endl;
		cout << "급여: " << salary_ << endl << endl;
	}

	void set_name(string name) { name_ = name; }
	void set_id(int id) { id_ = id; }
	void set_age(int age) { age_ =  age; }
	void set_salary(double salary) { salary_ = salary; }

	
};

int main() {

	Employee* a = new Employee("나소정", 2106, 18, 500.3);
	a->PrintInfo();
	delete a;

	Employee* b = new Employee[2];
	
	b[0].set_name("가나다");
	b[0].set_id(1111);
	b[0].set_age(108);
	b[0].set_salary(300);

	b[1].set_name("라마바");
	b[1].set_id(2222);
	b[1].set_age(26);
	b[1].set_salary(5000);

	for (int i = 0; i < 2; i++) {
		b[i].PrintInfo();
	}
	delete[] b;


	return 0;
}