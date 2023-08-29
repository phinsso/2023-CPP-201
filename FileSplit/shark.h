#pragma once
#include "animal.h"
#include <iostream>

using namespace std;

class Shark : public Animal {
public:
	void sing(void) { cout << "아기상어 뚜루루 뚜루" << endl; }

private:
	int teeth_;
};
