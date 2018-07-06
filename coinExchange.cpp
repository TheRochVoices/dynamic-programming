#include<iostream>
using namespace std;


int noOfWays(int coins[], int n, int sum)
{
	int arr[n+1][sum+1] = {0};
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0 && j==0)
				arr[i][j] = 1;
			else if(j==0)
				arr[i][j] = 1;
			else	
				arr[i][j] = 0;
		}
	}
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(coins[i-1] > j)
				arr[i][j] = arr[i-1][j];
			else
			{
				arr[i][j] = arr[i-1][j] + arr[i][j-coins[i-1]];	
			}
		}
	}
	
	
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			cout<<arr[i][j]<<'\t';	
		}
		cout<<endl;
	}
	return arr[n][sum];
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	int sum = 8;
	
	int ways = noOfWays(arr, 5, sum);
	cout<<"We can have "<<ways<<" possible combinations"<<endl;
}
