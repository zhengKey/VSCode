#include <iostream>

//桥接模式： 将抽象部分(业务功能)与实现部分(平台实现)分离，使它们都可以独立地变化。
//例子：开关有 拉链开关，闭合开关，电器有灯泡，风扇等。两者应该独立变化
//例子：手机有安卓苹果手机，软件有通讯录软件听歌软件，手机跟软件应该独立变化

class phoneSoft
{
public:
	virtual void Run() = 0;
};
class songSoft:public phoneSoft
{
public:
	virtual void Run(){
		std::cout<< "song Soft" <<std::endl;
	}
};

class gameSoft:public phoneSoft
{
public:
	virtual void Run(){
		std::cout<< "game Soft" <<std::endl;
	}
};

class Phone{
public:
	phoneSoft*   m_soft;
public:
	void setPhoneSoft(phoneSoft* temp)
	{
		m_soft = temp;
	}
	virtual void RunSoft() = 0;
};

class PhoneApple:public Phone{
public:
	virtual void RunSoft()
	{
		std::cout<<"apple phone: ";
		m_soft->Run();
	}
};
class PhoneAndroid:public Phone{
public:
	virtual void RunSoft()
	{
		std::cout<<"android phone: ";
		m_soft->Run();
	}
};
int main(int argc, char *argv[])
{

	Phone* brand = new PhoneApple();
	brand->setPhoneSoft(new gameSoft());
	brand->RunSoft();

	brand->setPhoneSoft(new songSoft());
	brand->RunSoft();

	brand  =  new PhoneAndroid();
	brand->setPhoneSoft(new gameSoft());
	brand->RunSoft();

	brand->setPhoneSoft(new songSoft());
	brand->RunSoft();
	system("pause");
}