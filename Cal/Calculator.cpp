#include "Calculator.h"



Calculator::Calculator()
{
}


Calculator::~Calculator()
{
}


void Calculator::setStr(char* str)
{
	_str = str;
}


double Calculator::getResult(char *s)
{
	char* str = s;
	State state = cal;
	double nums[20];
	char cals[20];
	char num[20];
	int nums_len = 0;
	int cals_len = 0;
	int num_length = 0;
	int spotnum = 0;
	int nenum = 0;
	nums[nums_len++] = 0;
	for (size_t i = 0; i < strlen(str); i++)
	{
		if ((str[i] <= '9'&&str[i] >= '0')||(str[i]=='.')||str[i]=='-') {
			if (str[i] == '.')
			{
				if (spotnum==0)
				{
					spotnum++;
				}
				else
				{
					printf("error input(dot) at %d \n", i);
					return -1;
				}
			}
			if (str[i] == '-')
			{
				if (nenum == 0)
				{
					nenum++;
				}
				else
				{
					printf("error input( - ) at %d \n", i);
					return -1;
				}
			}
			if (state==digitwihspace)
			{
				printf("error input(space) at %d \n",i);
				return -1;
			}
			state = digit;
			num[num_length++] = str[i];
		}
		if (str[i] = ' ') {
			if (state == digit)
			{
				num[num_length] = '\0';l
				memset(num, 0, 20 * sizeof(char));
				state = digitwihspace;
			}
		}
	}
	return 0.0;
}
