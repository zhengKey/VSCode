#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

//不重叠版本
char* my_strcpy(const char* src, char* dst)
{
	assert(src != nullptr && dst != nullptr);
	char * dest = dst;
	while((*dest++ = *src++) != '\0');
	return dst;
}

//重叠版本
char* my_strcpy_s(const char* src, char* dst, int n)
{
	assert(src != nullptr && dst != nullptr && n != 0);
	char * dest = dst + n -1;
	const char * srct = src + n -1;
	while( n --)
	{
		*dest-- = *srct--;
	}
	return dst;
}
int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;
	const char*src = "hello my baby";
	char*  dest = new char[strlen(src)+1];
	// my_strcpy(src,dest);
	my_strcpy_s(src,dest,strlen(src)+1);
	std::cout<< dest <<endl;
	system("pause");
}