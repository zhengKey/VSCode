#include <iostream>
//核心思想:父类完成主要步骤，留下virtual方法给子类继承后，子类自己实现具体步骤。
using namespace std;
class Base
{
public:
	void Show()
	{
		std::cout<<"I am "<<GetName() << std::endl;
	};
protected:
	virtual string GetName() = 0;
};
class xioaming : public Base
{
protected:
	virtual std::string GetName()
	{
		return "xiaoming";
	};
};
class xioahong : public Base
{
protected:
	virtual std::string GetName()
	{
		return "xiaohong";
	}
};

int main()
{
	std::cout << "Hello world!" << std::endl;
	xioaming* man = new xioaming();
	man->Show();
	xioahong* woman = new xioahong();
	woman->Show();
	system("pause");
	return 0;
}
