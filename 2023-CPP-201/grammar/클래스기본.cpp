//C++
#include<iostream>
#include<string>

using namespace std;

// 여러 데이터들을 하나의 의미있는 구조체로 묶어서 관리
struct drink {
	string moisture; //subun
	string additive; //chumga
};

int main(void) {

	// (struct drink)가 자료형 (c++에서는 drink만 써도 되지만 헷갈리지 않도록)
	struct drink strawberryMilk;
	strawberryMilk.moisture = "서울우유";
	strawberryMilk.additive = "킹스베리";

	cout << "수분: " << strawberryMilk.moisture << " 첨가물: " << strawberryMilk.additive << endl;
	

	return 0;
}