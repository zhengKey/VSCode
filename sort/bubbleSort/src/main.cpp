#include <iostream>
using namespace std;
#include <vector>
int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;

	int n = 15;
	int *arr =  new int[n];
	for(int i = 0 ;i < n; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i]<<"\t";
	}

	//bubble 排序
	bool flag = false;
	for(int i  = 0 ;i < n - 1; i++)
	{
		flag = false;
		for(int j = 0; j < n-1-i; j++ )
		{
			if(arr[j] < arr[j+1])
			{
				flag = true;
				int temp = arr[j+1];
				arr[j+1]  = arr[j];
				arr[j] = temp;
			}
		}
		if(flag == false)
		{
			//说明已经没有交换了。则可以输出结果了
			cout<<"sort had  finished"<<endl;
			break;
		}
	}
	//output
	for(int i = 0 ;i < n; i++)
	{
		cout << arr[i]<<"\t";
	}
	system("pause");
	
}