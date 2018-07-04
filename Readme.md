1.	Longest Common Subsequence
	Suppose we have a strings s1="ADHD" and s2 = "AHD"
	First make a 2d matrix of length of s1+1 and s2+2
	
	  ADHD
	 00000
	A00000 
	H00000
	D00000
	
	Traverse the strings, if the characters are not same, find the previous maximum length of the sequence i.e. the no. above or just before.
	If the chatacters match, find the maximum length of the sequence till the previous character i.e. the no. top left corner and add 1 in it. 

	  ADHD
	 00000
	A01111
	H01122
	D01223
	
2. 0/1 knapsack
	Firstly, sort w.r.t weights
	Make a 2d matrix of size (no. of weights + 1) * (W+1)
	
