//C++
#include<iostream>
#include<string>

using namespace std;

int main(void) {

	string str1 = "Hello";
	string str2 = "Hello";

	if (str2 == str1)
		cout << str1 << " 같다 " << str2;
	else
		cout << str1 << " 다르다 " << str2;

	return 0;
}