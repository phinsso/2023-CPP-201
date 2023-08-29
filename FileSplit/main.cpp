#include<iostream>

using namespace std;

class Animal {
public:
	void sing(void) {}

private:
	int hp_;
};

class Shark : public Animal {
public:
	void sing(void) { cout << "아기상어 뚜루루 뚜루" << endl; }

private:
	int teeth_;
};

class Whale : public Animal {
public:
	void sing(void) { cout << "우 우우 우 우" << endl; }

private:
	int bread_;

};

int main(void) {
	Animal a;
	Shark jaws;
	Whale lky;

	a.sing();
	jaws.sing();
	lky.sing();
}