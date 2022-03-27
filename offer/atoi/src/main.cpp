#include <iostream>
#include <string.h>
using namespace std;
int my_atoi(string s)
{
	int sign = 1;
	const char* pstr = s.c_str();
	while(*pstr == ' ')
	{
		pstr++;
	}

	if(*pstr == '+')
	{
		pstr++;
	}
	else if(*pstr == '-')
	{
		sign = -1;
		pstr++;
	}

	int sum = 0 ;
	while(*pstr != '\0')
	{
		if(*pstr < '0' || *pstr > '9')
		{
			break;//非数字
		}
		if(sum > INT_MAX/10 || (sum == INT_MAX/10 && INT_MAX%10 < (*pstr - '0')) )
		{
			return sign == -1 ? INT_MIN : INT_MAX;
		}

		sum = sum *10 + (*pstr - '0');
		pstr++;
	}
	return sum * sign;
}
int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;


	cout<<my_atoi(string("   214xx"))<<endl;
	cout<<my_atoi(string("21   47483647"))<<endl;
	cout<<my_atoi(string("  x214748  3647"))<<endl;
	cout<<my_atoi(string("2147483647"))<<endl;
	cout<<my_atoi(string("-2147483648"))<<endl;
	system("pause");
}