#pragma once
class Stack
{
private:
	char* chars;
	int maxLength;
	int currentPos;
public:
	Stack(int n) {
		maxLength = n;
		chars = new	char[n];
		currentPos = 0;
	};
	char pop() {
		if (currentPos != 0)
		{
			return chars[--currentPos];
		}
		else {
			return '\0';
		}
	}
	char push(char c) {
		if () {
		
		}
	}
	~Stack();
};

