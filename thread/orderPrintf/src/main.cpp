#include <iostream>
#include <thread>
using namespace std;
#include <mutex>
mutex  m1;
mutex  m2;
mutex  m3;


void printf1()
{
	m1.lock();
	cout<<"thread 1"<<endl;
	m2.unlock();
}
void printf2()
{
	m3.lock();
	cout<<"thread 2"<<endl;
	m1.unlock();
}
void printf3()
{
	m2.lock();
	cout<<"thread 3"<<endl;
	m3.unlock();
}
int main(int argc, char *argv[])
{
	m2.lock();
	m3.lock();
	std::cout << "Hello world!" << std::endl;
	std::thread  obj1(printf1);
	std::thread  obj2(printf2);
	std::thread  obj3(printf3);

	obj1.join();
	obj2.join();
	obj3.join();
	system("pause");
}