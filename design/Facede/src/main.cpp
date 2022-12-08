#include <iostream>

//外观模式：外部与一个子系统的通信必须通过一个统一的外观对象进行，为子系统中的一组接口提供一个一致的界面

class subSysOne{
public:
	void funOne()
	{
		std::cout<<"funOne"<<std::endl;
	}

};
class subSysTwo{
public:
	void funTwo()
	{
		std::cout<<"funTwo"<<std::endl;
	}

};
class subSysThree{
public:
	void funThree()
	{
		std::cout<<"funThree"<<std::endl;
	}

};

class Facede{
private:
	subSysOne* one;
	subSysTwo* two;
	subSysThree* three;
public:
	Facede()
	{
		one = new subSysOne();
		two = new subSysTwo();
		three = new subSysThree();
	}	
	~Facede()
	{
		delete one;
		delete two;
		delete three;
	}

	void FacedeFun()
	{
		one->funOne();
		two->funTwo();
		three->funThree();
	}
};
int main(int argc, char *argv[])
{
	Facede* face = new Facede();
	face->FacedeFun();
	system("pause");
	return 0;
}