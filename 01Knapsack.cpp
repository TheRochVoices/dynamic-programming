#include<iostream>
using namespace std;

int knapsack(int w[], int v[], int l, int W)
{
	int arr[l+1][W+1] = {{0}};
	
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<W+1;j++)
		{
			arr[i][j] = 0;
		}
	}	

	/*for(int i=0;i<l;i++)
	{
		for(int j=0;j<W;j++)
		{
			cout<<arr[i][j]<<'\t';
		}
		cout<<endl;
	}*/
		
	for(int i=0;i<l+1;i++)
	{
		for(int j=0;j<W+1;j++)
		{
			if(i==0 || j==0)
			{
				arr[i][j] = 0;
			}
			else if(w[i-1] > j)
			{
				arr[i][j] = arr[i-1][j];
			}
			else if(w[i-1] <= j)
			{
			
				arr[i][j] = arr[i-1][j] > v[i-1] + arr[i-1][j-w[i-1]] ? arr[i-1][j] : v[i-1] + arr[i-1][j-w[i-1]];
			}
		}
	}
	
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<W+1;j++)
		{
			cout<<arr[i][j]<<'\t';
		}
		cout<<endl;
	}
	return arr[l][W];
}



int main()
{
	int w[5] = {1, 2, 3, 4, 5};
	int v[5] = {1, 4, 4, 5, 7};
	int W = 9;
	int n = knapsack(w, v, 5, W);
	cout<<"Maximum weight we can have is "<<n<<endl;
}
