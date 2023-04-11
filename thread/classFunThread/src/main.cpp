#include <iostream>
#include<thread>
class  task
{
private:
    /* data */
public:
     task(/* args */)
     {
         std::cout <<"father thread: "<< std::this_thread::get_id() << std::endl;
         std::thread  m_thread([this]{
                 std::cout <<"son thread: "<< std::this_thread::get_id() << std::endl;
                 processThread();
         });
         m_thread.join();
     };
    void processThread();
    ~ task(){};
};

void task::processThread()
{
    std::cout <<"processThread: "<< std::this_thread::get_id() << std::endl;
}

int main(int argc, char *argv[])
{
    std::cout << "Hello world!" << std::endl;
    task a;
    system("pause");
}
