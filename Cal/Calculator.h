#pragma once
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
enum State {
	digit,
	cal,
	brackets,
	digitwihspace
};
class Calculator
{
private:
	char * _str;
	State state;
	double getResult(char *);
public:
	Calculator();
	~Calculator();
	void setStr(char* _str);
	double GetResult() {
		return getResult(_str);
	};
};

