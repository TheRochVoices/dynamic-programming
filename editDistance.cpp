#include<iostream>
#include<string>
using namespace std;


int min(int a, int b, int c)
{
	if(a<b && a<c)
		return a;
	else if(b<a && b<c)
		return b;
	else
		return c;
}
int editDistance(string a, string b)
{
	int lena = a.length();
	int lenb = b.length();
	int arr[lena+1][lenb+1] = {0};
	
	for(int i=0;i<lena+1;i++)
	{
		for(int j=0;j<lenb+1;j++)
		{
			if(i==0)
				arr[i][j] = j;
			else if(j==0)
				arr[i][j] = i;
			else 
				arr[i][j] = 0;
		}
	}
	arr[0][0] = 0;
	
	for(int i=1;i<lena+1;i++)
	{
		for(int j=1;j<lenb+1;j++)
		{
			if(a[i-1] == b[j-1])
			{
				arr[i][j] = arr[i-1][j-1];
			}
			else
				arr[i][j] = min(arr[i-1][j], arr[i][j-1], arr[i-1][j-1]) + 1;
		}
	}

	for(int i=0;i<lena+1;i++)
	{
		for(int j=0;j<lenb+1;j++)
		{
			cout<<arr[i][j]<<'\t';
		}
		cout<<endl;
	}
	cout<<arr[lena][lenb]<<endl;
}

int main()
{
	string a = "adceg";
	string b = "abcfg";
	editDistance(a, b);
}
