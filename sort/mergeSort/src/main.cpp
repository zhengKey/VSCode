#include <iostream>
using namespace std;

void mergeArrSort(int left,int mid,int right,int arr[],int temp[])
{
	int k = 0;
	int i = left;
	int j = mid+1;	
	while(i <= mid && j <= right)
	{
		if(arr[i] < arr[j])
		{
			temp[k] = arr[i];
			k++;i++;
		}
		else{
			temp[k] = arr[j];
			k++;j++;
		}
	}
	while(i <= mid)
	{
		temp[k++] = arr[i++];
	}
	while(j <= right)
	{
		temp[k++] = arr[j++];
	}

	k = 0;
	for(int i = left; i < right+1 ; i++)
	{
		arr[i] = temp[k++];
	}
}

void mergeSort(int left, int right,  int arr[],int temp[])
{
	if(left < right)
	{
		int mid = (left + right)/2;
		mergeSort( left, mid, arr,temp);
		mergeSort( mid + 1, right, arr,temp);
		//合并
		mergeArrSort(left,mid,right,arr,temp); 
	}
}
int main(int argc, char *argv[])
{
	int n = 15;
	int *arr =  new int[n];
	int *temp = new int[n];
	for(int i = 0 ;i < n; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i]<<"\t";
	}

	//quick sort
	mergeSort(0,n-1,arr,temp);
	//output
	for(int i = 0 ;i < n; i++)
	{
		cout << arr[i]<<"\t";
	}
	system("pause");
}
