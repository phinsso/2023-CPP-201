#include<iostream>

using namespace std;

void plus2(int& num) {
	num += 2;
}

int main(void) {

	int a = 3;
	plus2(a);

	cout << a << endl;

	return 0;
}