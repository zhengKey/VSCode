#include <iostream>

//原型模式：：从一个对象再创建另外一个可定制的对象，拷贝自己

class prototype
{

public:
	virtual prototype* clone() = 0;
};

class concretePrototype:public prototype
{
	
public:
	int   nRet;
	concretePrototype(/* args */){nRet = 10;};
	~concretePrototype();
	concretePrototype(const concretePrototype& rhs)//拷贝构造函数
	{
		nRet = rhs.nRet;
	}
	concretePrototype* clone()
	{
		return new concretePrototype(*this);
	}
};



int main(int argc, char *argv[])
{

	concretePrototype* conProA = new concretePrototype();
	std::cout << conProA->nRet <<std::endl;
	//拷贝对象
	concretePrototype* conProB = conProA->clone();
	std::cout << conProB->nRet <<std::endl;
	system("pause");
}