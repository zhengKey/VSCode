#include <iostream>
#include <thread>
#include<semaphore.h>
using namespace std;
sem_t  printfSemH;
sem_t  printfSemO;
int n = 0;
//输出两个H一个O
void printf1()
{
	while(n < 100)
	{
		sem_wait(&printfSemH);
		cout<<"thread 1"<<" "<<"H"<<endl;
		n++;
		sem_post(&printfSemO);
	}
}
void printf2()
{	
	while(n<100)
	{
		sem_wait(&printfSemO);
		sem_wait(&printfSemO);
		cout<<"thread 2"<<" "<<"O"<<endl;
		n++;
		sem_post(&printfSemH);
		sem_post(&printfSemH);
	}

}

int main(int argc, char *argv[])
{
	
	std::cout << "Hello world!" << std::endl;
	sem_init(&printfSemH,0,2);
	sem_init(&printfSemO,0,0);
	std::thread  obj1(printf1);
	std::thread  obj2(printf2);

	obj1.join();
	obj2.join();

	system("pause");
}