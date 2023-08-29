#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Hero {
public:
	// 생성자
	Hero(string name, T health, T attack, T defence)
		: name(name), health(health), attack(attack), defence(defence) {}

	void Print(void) {
		cout << "이름: " << name << endl;
		cout << "체력: " << health << endl;
		cout << "공격: " << attack << endl;
		cout << "방어: " << defence << endl;
	}

private:
	string name;
	T health;
	T attack;
	T defence;
};

int main(void) {

	Hero<int> *h1 = new Hero<int>("소정", 1000, 80, 150);
	h1->Print();
	delete h1;

	return 0;
}