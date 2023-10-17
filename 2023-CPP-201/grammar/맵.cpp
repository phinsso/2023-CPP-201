#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
	// key: 문자열, value: 정수
	map<string, int> moving;

	moving["번개맨"] = 1987;
	moving["장희수"] = 2000;
	moving["봉평"] = 1959;

	// map은 순서가 없기 때문에 iterator로만 반복을 해야한다.
	// auto는 주로 복잡한 자료형을 대체할 때 사용한다.
	for (auto iter = moving.begin(); iter != moving.end(); iter++) {
		// first: key, second: value
		cout << iter->first << "   " <<  iter->second << endl;
	}

}