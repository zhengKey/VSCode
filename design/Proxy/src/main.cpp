#include <iostream>

//代理模式： 代理类和真实类有共同基类，代理类中有真实类的引用，调用代理类接口，实际实现为真实类
class subject
{
	virtual bool Request() = 0;
};

class realSubject:public subject
{
public:
	bool Request()
	{
		std::cout << "real subject done"<<std::endl;
	}
};


class proxySubject:public subject
{
private:
	realSubject * realQuest;
public:
	bool Request()
	{
		realQuest = new realSubject();
		realQuest->Request();
		delete realQuest;
	}
};
int main(int argc, char *argv[])
{

	proxySubject* proxy = new proxySubject();
	proxy->Request();
	system("pause");
}