
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int LCS(string s1, string s2)
{
	int l1 = s1.length() + 1;
	int l2 = s2.length() + 1;
	int arr[l1][l2] = {0};

	
	for(int i=0; i<l1; i++)
	{
		for(int j=0; j<l2;j++)
		{
			arr[i][j] = 0;
		}
	}
	

	for(int i=1; i<l1; i++)
	{
		for(int j=1; j<l2 ;j++)
		{
			if(s1[i-1] == s2[j-1])		//If the characters match, we have found another character to add to the LCS.
			{
				arr[i][j] = arr[i-1][j-1] + 1;
			}
			else						//If don't, find the maximum subsequence that we found previously.
			{
				arr[i][j] = arr[i][j-1] > arr[i-1][j]?arr[i][j-1]:arr[i-1][j];
			}
		}	
	}
	
	
	for(int i=0; i<l1; i++)
	{
		for(int j=0; j<l2; j++)
		{
			cout<<arr[i][j]<<'\t';
		}
		cout<<endl;
	}	
	
	return arr[l1-1][l2-1];
}

int main()
{
	string s1 = "abcdaf";
	string s2 = "acbcf";
	int l = LCS(s1, s2);
	cout<<"Length of Longest Common "<<l<<endl;
}
