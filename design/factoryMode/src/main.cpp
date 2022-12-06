#include <iostream>
using namespace std;

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
class IFactory{

	public:
	virtual IFruit* create() = 0;
};
class appleFactory:public IFactory{

	public:
    IFruit* create()
	{
		return new apple();
	}
};
class bananaFactory:public IFactory{

	public:
 	IFruit* create() 
	{
		return new banana();
	}
};


int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;

	IFactory*  fac = new appleFactory();
	IFruit* fruit =  fac->create();
	fruit->show();

	fac = new bananaFactory();
	fruit = fac->create();
	fruit->show();
	system("pause");
}
