#include<iostream>
#include<string>
using namespace std;

int subSum(int nums[], int n, int S)
{
	int arr[n+1][S+1];
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<S+1;j++)
		{
			arr[i][j] = 0;
		}
	}
	arr[0][0] = 1;
	for(int i=1;i<n+1;i++)
	{
		for(int j=0;j<S+1;j++)
		{
			if(arr[i-1][j] == 1)
			{
				arr[i][j] = 1; 
			}
			else if(nums[i-1] > j)
			{
				arr[i][j] = arr[i-1][j];
			}
			else if(nums[i-1] == j)
			{
				arr[i][j] = 1;
			}
			else if(arr[i-1][j-nums[i-1]] == 1) 
			{
				arr[i][j] = 1;
			}
		}
	}
	
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<S+1;j++)
		{
			cout<<arr[i][j]<<'\t';
		}
		cout<<'\n';
	}
	
	return arr[n][S];	
} 

int main()
{
	int arr[4] = {1, 2, 5, 7};
	int sum = 12;
	int stat = subSum(arr, 4, sum);
	string str[2] = {"We cannot", "We can"};
	cout<<str[stat];
	cout<<" make "<<sum<<" with {\t";	
	for(int i=0;i<4;i++)
	{
		cout<<arr[i]<<'\t';
	}	
	cout<<"}"<<endl;
}
