#include <iostream>
#include <thread>
using namespace std;
int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;
	std::thread a([=]{
		
		std::chrono::milliseconds dura(2000);
		std::this_thread::sleep_for(dura);
		std::cout<<"helloaaa"<<endl;
	});
	
	std::thread ab([=]{
		std::cout<<"hellobbb"<<endl;}
	);

    //说明线程之间的join是不相互阻塞的。当a线程sleep2秒  b可以先执行
	a.join();
	ab.join();
	std::cout<<"main thread";
	system("pause");
}