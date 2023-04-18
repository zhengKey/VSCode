#include <iostream>
#include <thread>
using namespace std;


void startthread()
{
    //这个子线程对象不会析构
    std::thread th([](){
        while(1)
        {
            std::cout<<"thread  son "<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));  // 睡眠 1 秒钟
        }
    });
    th.detach();
}


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
    startthread();
	std::cout<<"main thread"<<std::endl;
	system("pause");
}