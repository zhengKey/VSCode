#include <iostream>
#include <string.h>
using namespace std;
class myString
{
private:
	/* data */
	char*  m_pdata;
public:
	myString(char* val = nullptr);
	myString(const myString& other);
	myString& operator=(const myString& other);
	~myString();
};

myString::myString(char* val)
{
	std::cout<<"construct function"<<endl;
	if(val == nullptr)
	{
		m_pdata = new char[1];
		*m_pdata = '\0';
	}
	else{

		int len = strlen(val);
		m_pdata = new char[len+1];
		strcpy(m_pdata,val);
	}
}
myString::myString(const myString& other)
{
	std::cout<<"copy function"<<endl;
	int len = strlen(other.m_pdata);
	m_pdata = new char[len+1];
	strcpy(m_pdata,other.m_pdata);
}
myString& myString::operator=(const myString& other)
{
	std::cout<<"= function"<<endl;
	//第一种，可能出现删除内存后分配内存失败导致m_pdata为null
	if(this == &other)
	{
		return *this;
	}
	delete [] m_pdata;
	m_pdata = nullptr;
	int len = strlen(other.m_pdata);	
	m_pdata = new char[len + 1];
	strcpy(m_pdata,other.m_pdata);

	return *this;

	//第二种方法,创建临时实例
	// if(this != &other)
	// {
	// 	myString  temp(other);
	// 	char* ptemp = temp.m_pdata;
	// 	temp.m_pdata = m_pdata;
	// 	m_pdata = ptemp;
	// }
	// return *this;
}

myString::~myString()
{
	std::cout<<"destruct function"<<endl;
	delete[]m_pdata;
	m_pdata = nullptr;
}

int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;
	
	myString  a("hello");
	cout<<"11111"<<endl;
	myString  b = a;
	cout<<"22222"<<endl;
	myString  c;
	c = a;
	cout<<"33333"<<endl;
	system("pause");
}