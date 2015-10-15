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
	bool flag = false;
	for (size_t i = 0; i < strlen(str); i++)
	{
		if ((str[i] <= '9'&&str[i] >= '0') || (str[i] == '.')) {
			if (str[i] == '.')
			{
				if (spotnum == 0)
				{
					spotnum++;
				}
				else
				{
					printf("error input(%c) at %d \n", str[i], i+1);
					return -1;
				}
			}
			if (state == digitwihspace)
			{
				printf("error input(%c) at %d \n", str[i], i+1);
				return -1;
			}
			if (str[i] != '-')
			{
				state = digit;
				num[num_length++] = str[i];
			}
		}
		else if (str[i] == ' ') {
			if (state == digit)
			{
				state = digitwihspace;
			}
		}
		else if (str[i] == '+' || str[i] == '*' || str[i] == '/' || str[i] == '-') {
			if (state == cal)
			{
				if (str[i] == '-') {
					flag = true;
				}
				else {
					printf("error input(%c) at %d \n", str[i], i+1);
					return -1;
				}
			}
			else if(str[i-1]==')'){
				cals[cals_len++] = str[i];
				state = cal;
			}
			else {
				num[num_length] = '\0';
				if (flag)
				{
					nums[nums_len++] = -atof(num);
					flag = false;
				}
				nums[nums_len++] = atof(num);
				num_length = 0;
				memset(num, 0, 20 * sizeof(char));
				cals[cals_len++] = str[i];
				state = cal;
			}
		}
		else if (str[i] == '(')
		{
			if (state != cal)
			{

				printf("error input(%c) at %d \n", str[i - 1], i);
				return -1;
			}
			char *newS = new char[50];
			int j;
			for (j = i + 1;str[j] != ')';j++)
			{
				newS[j - i - 1] = str[j];
			}
			newS[j - i - 1] = '\0';
			nums[nums_len++] = getResult(newS);
			i = j;
			state = digit;
		}
		else {
			printf("error input(%c) at %d \n", str[i], i+1);
			return -1;
		}
		if (i == strlen(str) - 1)
		{
			num[num_length] = '\0';
			if (flag)
			{
				nums[nums_len++] = -atof(num);
				flag = false;
			}
			nums[nums_len++] = atof(num);
			num_length = 0;
			memset(num, 0, 20 * sizeof(char));
		}
	}
	/*for (int i = 0;i < nums_len;i++)
	{
		printf("%d -> %f \n", i, nums[i]);
	}*/
	if (cals_len==0)
	{
		return nums[0];
	}
	double ssresult;
	for (int i = 0;i < cals_len;i++)
	{
		if (cals[i] == '/')
		{
			double result = nums[i] / nums[i + 1];
		//	printf("%f %c %f = %f\n", nums[i], cals[i], nums[i + 1], result);
			for (int j = i;j < cals_len;j++)
			{
				cals[j] = cals[j + 1];
			}
			nums[i] = result;
			ssresult = result;
			for (int j = i + 1;j < nums_len;j++)
			{
				nums[j] = nums[j + 1];
			}
			i--;
		}
	}
	for (int i = 0;i < cals_len;i++)
	{
		if (cals[i] == '*')
		{
			double result = nums[i] * nums[i + 1];
		//	printf("%f %c %f = %f\n", nums[i], cals[i], nums[i + 1], result);
			for (int j = i;j < cals_len;j++)
			{
				cals[j] = cals[j + 1];
			}
			nums[i] = result;
			ssresult = result;
			for (int j = i + 1;j < nums_len;j++)
			{
				nums[j] = nums[j + 1];
			}
			i--;
		}
	}
	for (int i = 0;i < cals_len;i++)
	{
		if (cals[i] == '+')
		{
			double result = nums[i] + nums[i + 1];
		//	printf("%f %c %f = %f\n", nums[i], cals[i], nums[i + 1], result);
			for (int j = i;j < cals_len;j++)
			{
				cals[j] = cals[j + 1];
			}
			nums[i] = result;
			ssresult = result;
			for (int j = i + 1;j < nums_len;j++)
			{
				nums[j] = nums[j + 1];
			}
			i--;
		}
	}
	for (int i = 0;i < cals_len;i++)
	{
		if (cals[i] == '-')
		{
			double result = nums[i] - nums[i + 1];
		//	printf("%f %c %f = %f\n", nums[i], cals[i], nums[i + 1], result);
			for (int j = i;j < cals_len;j++)
			{
				cals[j] = cals[j + 1];
			}
			nums[i] = result;
			ssresult = result;
			for (int j = i + 1;j < nums_len;j++)
			{
				nums[j] = nums[j + 1];
			}
			i--;
		}
	}
	return ssresult;
}
