#include <iostream>

//适配器模式： 将一个类的接口转换成客户希望的另外一个接口。

class target{
public:
	virtual bool  Request() =0;
};

class Adaptee  //这里并没有继承target。不同于代理模式
{
public:
	bool SpecialRequest()
	{
		std::cout << "special request"<<std::endl;
	}
};

class Adapter:public target
{

private:
	Adaptee*  adaptee;
public:
	bool Request()
	{
		adaptee->SpecialRequest();
	}
	Adapter()
	{
		adaptee = new Adaptee();
	}
	~Adapter()
	{
		delete adaptee;
	}
};


int main(int argc, char *argv[])
{
	Adapter*  ada = new Adapter();
	ada->Request();
	system("pause");
}