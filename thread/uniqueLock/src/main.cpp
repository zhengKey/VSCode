#include <iostream>
#include <mutex>
using namespace std;
#include <thread>
int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;
	std::mutex m_mutex;
	std::thread  newThread[10];
	for(int i = 0; i < 10 ;i++)
	{
		//这里要用引用，不可用值传递
		newThread[i] = std::thread([&]{
			std::unique_lock<std::mutex> lock(m_mutex);
			std::cout<<"number"<<i<<endl;
		});
	}
	for(auto &thread : newThread)
	{
		thread.join();
	}
	system("pause");
}