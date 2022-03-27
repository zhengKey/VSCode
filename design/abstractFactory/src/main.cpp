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
	virtual IBanana* createrBanana() = 0;
	virtual IApple* createrApple() = 0;
};
class ChinaFactory:public IFactory{

	public:
    IApple* createrApple()
	{
		return new ChinaApple();
	}
	IBanana* createrBanana()
	{
		return new ChianBanana();
	}
};
class UsaFactory:public IFactory{

	public:
    IApple* createrApple()
	{
		return new UsaApple();
	}
	IBanana* createrBanana()
	{
		return new UsaBanana();
	}
};


int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;

	IFactory*  fac = new ChinaFactory();
	IApple* chinaApple =  fac->createrApple();
	IBanana* chianBanana = fac->createrBanana();
	chinaApple->show();
	chianBanana->show();

    fac = new UsaFactory();
	IApple* usaApple =  fac->createrApple();
	IBanana* usaBanana = fac->createrBanana();
	usaApple->show();
	usaBanana->show();

	system("pause");
}
