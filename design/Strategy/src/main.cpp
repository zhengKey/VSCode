#include <iostream>

//策略模式： 定义一组算法，将每个算法封装起来，算法之间可以互相替换。

class Strategy{
public:
	virtual double getResult(int a, int b) = 0;
};
class algorithmAdd:public Strategy
{

public:	
	double getResult(int a, int b)
	{
		return a+b;
	}

};
class algorithmSub:public Strategy
{

public:	
	double getResult(int a, int b)
	{
		return a-b;
	}

};
class algorithmMulti:public Strategy
{

public:	
	double getResult(int a, int b)
	{
		return a*b;
	}

};


class Context
{
private:
	Strategy* opt;
public:
	Context(Strategy* sgy)
	{
		opt = sgy;
	}
	double GetResult(int a, int b)
	{
		opt->getResult(a,b);
	}
};


int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;

	Context* context = new Context(new algorithmAdd());
	std::cout<< context->GetResult(9,3) << std::endl;//12

	context = new Context(new algorithmSub()) ;
	std::cout<< context->GetResult(9,3)<< std::endl;//6

	context = new Context(new algorithmMulti());
	std::cout<< context->GetResult(9,3)<< std::endl;//27
	
	system("pause");
}