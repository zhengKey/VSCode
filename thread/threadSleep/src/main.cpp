#include <iostream>
using namespace std;
#include <thread>
#include <mutex>
int  n = 0;
std::mutex  mtx;
void printA()
{
	while(n < 2000)
	{
	    mtx.lock();
		std::cout<<"A"<<n<<endl;
		n++;
		
		std::cout<<"start sleep"<<n<<endl;
		std::chrono::milliseconds dura(200);
    	std::this_thread::sleep_for(dura);
		mtx.unlock();
	}
}
void printB()
{
	while(n < 2000)
	{
		mtx.lock();
		std::cout<<"B"<<n<<endl;
		n++;
		mtx.unlock();
	}
}

//结论：如果不加锁sleep会导致切换线程，如果加锁sleep不会放开锁
// 线程是随机切换的。a线程解锁，不一定就会让给b线程拿到锁。
int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;

	std::thread  a(printA);
	std::thread  b(printB);
	a.join();
	b.join();

	system("pause");
}