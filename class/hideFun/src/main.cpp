#include <iostream>
using namespace std;
class Base{

	public:
	Base()
	{ a = 20;};
	void add()
	{
		cout<<"base add"<<endl;
	}
	int a;
};
class Derive:public Base{
	public:
	Derive()
	{ this->a = 10;};
	void add()
	{
		cout << "derive add"<<endl;
	}
	int a;
};
int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;
	Base *bp = new Derive();
	bp->add();
	bp->Base::add();
	//bp->Derive::add();  这里调用错误

	//子类隐藏了 父类的同名函数和变量。会优先调用子类的
	Derive *dp =  new Derive();
	dp->add();
	std::cout<<dp->a<<endl;
	system("pause");

}