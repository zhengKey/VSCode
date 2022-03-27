#include <iostream>
using namespace std;
#include <mutex>
// class singleton
// {
// 	//饿汉式
// 	static  singleton* m_instance;
// public:
// 	static  singleton* getInstance()
// 	{
// 		cout<<"this is a singleton"<<endl;
// 		return m_instance;
// 	}
// };
// singleton* singleton::m_instance = new singleton();


// std::mutex  	m_mtx;
// class singleton
// {
// 	//懒汉式
// 	static  singleton* m_instance;
// public:
// 	static  singleton* getInstance()
// 	{
// 		if(m_instance == nullptr)
// 		{
// 			m_mtx.lock();
// 			if(m_instance ==  nullptr)
// 			{
// 				cout << "this is lazy singleton"<<endl;
// 				m_instance = new singleton();
// 			}
// 			m_mtx.unlock();
// 			return m_instance;
// 		}
// 	}
// };
// singleton* singleton::m_instance = nullptr;


class singleton{
	public:
	static singleton* m_instance;
	static singleton* getInstance(){
		 std::call_once(m_flag,[](){
			 cout<< "call_once "<<endl;
			 m_instance = new singleton();
		 });
		 return m_instance;
	}
	public:
	static std::once_flag   m_flag;
};
std::once_flag singleton::m_flag;
singleton* singleton::m_instance;

int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;
	singleton::getInstance();
	system("pause");
}