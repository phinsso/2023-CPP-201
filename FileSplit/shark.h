#pragma once
#include "animal.h"


class Shark : public Animal {
public:
	void sing(void);

private:
	int teeth_;
};
