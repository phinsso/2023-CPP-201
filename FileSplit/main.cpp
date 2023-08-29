#include<iostream>
#include "animal.h"
#include "shark.h"
#include "whale.h"

using namespace std;

int main(void) {
	Animal a;
	Shark jaws;
	Whale lky;

	a.sing();
	jaws.sing();
	lky.sing();
}