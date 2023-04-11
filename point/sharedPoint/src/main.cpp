#include <iostream>
#include<memory>
using namespace std;
void  add(std::shared_ptr<int>& a)
{
	std::cout<<a.use_count()<<std::endl;
}

//不是引用会增加计数
void  addref(std::shared_ptr<int> a)
{
	std::cout<<a.use_count()<<std::endl;
}

int main(int argc, char *argv[])
{
	 std::cout << "Hello world!" << std::endl;
	 int* p = new int;
	 shared_ptr<int> sptr1( p);
	 shared_ptr<int> sptr2(sptr1);
	 //可以下方这样初始化，引用计数增加
	 //shared_ptr<int> sptr2 = sptr1;
	 shared_ptr<int> sptr3;
	 sptr3 = sptr1;
	 //std::cout   3
	 std::cout<<sptr1.use_count()<<sptr2.use_count()<<sptr3.use_count();

	 add(sptr1);
	 std::cout<<sptr1.use_count()<<sptr2.use_count()<<sptr3.use_count();

     addref(sptr1);
	 std::cout<<sptr1.use_count()<<sptr2.use_count()<<sptr3.use_count();
     //不能这样同时用p初始化。这样sptr1和sptr2引用计数都是1 	
	// shared_ptr<int> sptr2( p);
	 system("pause");
}