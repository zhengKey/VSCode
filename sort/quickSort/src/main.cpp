#include <iostream>
using namespace std;

void quickSort(int left, int right,  int arr[])
{
	int begin = left;
	int end = right;
	int base = left;
	int n = right - left + 1;
	if(begin >= end) return;
	while(left < right)
	{
		//右指针先移动
		while(arr[right] >= arr[base] && left < right)
		{
			right --;
		}
		if(arr[right] < arr[base])
		{
			int temp = arr[base];
			arr[base] = arr[right];
			arr[right] = temp;
			base = right;
		}

		//左指针移动
		while(arr[left] <= arr[base] && left < right)
		{
			left ++;
		}
		if(arr[left] > arr[base])
		{
			int temp = arr[base];
			arr[base] = arr[left];
			arr[left] = temp;
			base = left;
		}
	}

	quickSort( begin, base - 1, arr);
	quickSort( base + 1, end - 1, arr); 
}

int main(int argc, char *argv[])
{
	int n = 15;
	int *arr =  new int[n];
	for(int i = 0 ;i < n; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i]<<"\t";
	}

	//quick sort
	quickSort(0,n-1,arr);
	//output
	for(int i = 0 ;i < n; i++)
	{
		cout << arr[i]<<"\t";
	}
	system("pause");
}
