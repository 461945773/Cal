#include "Calculator.h"
#include <iostream>
using namespace std;

int main() {
	char * str1 = "1 + 2 + 4 * 3+(9-1)*(3+2)/5";
	char * str2 = "";
	bool flag = false;
	Calculator c;
	printf("ÇëÊäÈëÔËËãÊ½ : \n");
	char *s = new char[50];
	cin >> s;
	c.setStr(s);
	printf(" %s = %.2f \n", s, c.GetResult());
}