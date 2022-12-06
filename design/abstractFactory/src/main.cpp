#include <iostream>
using namespace std;

class IApple{
	public:
	virtual void show() = 0; 
};
class ChinaApple:public IApple{
	void show()
	{
		cout<<"china apple"<<endl;
	}
};
class UsaApple:public IApple{
	void show()
	{
		cout<<"usa apple"<<endl;
	}
};
class IBanana{
	public:
	virtual void show() = 0; 
};
class ChianBanana:public IBanana{
	void show()
	{
		cout <<"chian banana"<<endl;
	}
};
class UsaBanana:public IBanana{
	void show()
	{
		cout <<"usa banana"<<endl;
	}
};
class IFactory{

	public:
	virtual IBanana* createBanana() = 0;
	virtual IApple* createApple() = 0;
};
class ChinaFactory:public IFactory{

	public:
    IApple* createApple()
	{
		return new ChinaApple();
	}
	IBanana* createBanana()
	{
		return new ChianBanana();
	}
};
class UsaFactory:public IFactory{

	public:
    IApple* createApple()
	{
		return new UsaApple();
	}
	IBanana* createBanana()
	{
		return new UsaBanana();
	}
};


int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;

	IFactory*  fac = new ChinaFactory();
	IApple* chinaApple =  fac->createApple();
	IBanana* chianBanana = fac->createBanana();
	chinaApple->show();
	chianBanana->show();

    fac = new UsaFactory();
	IApple* usaApple =  fac->createApple();
	IBanana* usaBanana = fac->createBanana();
	usaApple->show();
	usaBanana->show();

	system("pause");
}
