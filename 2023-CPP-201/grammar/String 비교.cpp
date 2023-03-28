//C
#include<stdio.h>
#include<string.h>

//C++
#include<iostream>
#include<string>

using namespace std;

int main(void) {

	string str1 = "Hello";
	string str2 = "World";

	// c++ string 편리해
	// str2가 str1보다 사전에 더 늦게 나온다


	// 함수 인자 위치와 결과값(-1, 1) 주의해서 보기!

	if (str2 > str1)
		cout << "str2 > str1";
	else if (str2 < str1)
		cout << "str2 < str1";
	else
		cout << "str2 == str1";

	return 0;
}