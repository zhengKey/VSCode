#include <iostream>
#include <vector>
//观察者模式： 定义对象间的一种一对多依赖关系，使得每当一个对象状态发生改变时，其相关依赖对象皆得到通知

//观察者
class Observer
{
public:
	virtual void update() = 0;
};
//观察者中也可以引入被观察者的引用。反向通知被观察者
class concretObs : public Observer
{
	std::string  m_name;
public:
	concretObs(std::string name)
	{
		m_name = name;
	}
	void update()
	{
		std::cout<< m_name << "   update"<<std::endl;
	}
};
//被观察者
class Subject
{
	std::vector<Observer*> m_observer;
public:
	virtual void add(Observer * obs)
	{
		m_observer.push_back(obs);
	}
	virtual void Notify()
	{
		std::vector<Observer*>::iterator it= m_observer.begin();
		while (it != m_observer.end())
		{
			(*it)->update();
			it ++;
		}	
	}
};


int main(int argc, char *argv[])
{

	Subject * sub = new Subject();
	concretObs* obs1 = new concretObs("xiaoming");
	concretObs* obs2 = new concretObs("xiaohong");
	concretObs* obs3 = new concretObs("xiaogang");

	sub->add(obs1);
	sub->add(obs2);
	sub->add(obs3);
	sub->Notify();
	system("pause");
}