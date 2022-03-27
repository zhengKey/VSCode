#include <iostream>
using namespace std;

//简单工厂,产品抽象，工厂具体。

class IFruit{
	public:
	virtual void show() = 0; 
};
class apple:public IFruit{
	void show()
	{
		cout<<"apple"<<endl;
	}
};
class banana:public IFruit{
	void show()
	{
		cout <<"banana"<<endl;
	}
};
class Factory{

	public:
	IFruit* creater(int type)
	{
		if(type == 0)
		{
			return new apple();
		}
		else if(type == 1)
		{
			return new banana();
		}
	}
};
int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;

	Factory*  fac = new Factory();
	
	IFruit* fruit =  fac->creater(0);
	fruit->show();
	fruit = fac->creater(1);
	fruit->show();
	system("pause");
}