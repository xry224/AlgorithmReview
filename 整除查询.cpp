/*
������ѯ

����

Given an array of positive integers and many queries for divisibility. In every query Q[i], we are given an integer K , we need to count all elements in the array which are perfectly divisible by K.

Constraints:1<=T<=1001<=N,M<=1051<=A[i],Q[i]<=105

����

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines. First line of each test case contains two integers N & M, second line contains N space separated array elements and third line contains M space separated queries.

���

For each test case,In new line print the required count for each query Q[i].

�������� 1

2
6 3
2 4 9 15 21 20
2 3 5
3 2
3 4 6
2 3

������� 1

3 3 2
2 2


*/
#include <iostream>
#include <vector>
using namespace std;
void printArr(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		if (i == 0)
		{
			cout << arr[i];
		}
		else
		{
			cout << " " << arr[i];
		}
	}
	cout << endl;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> arr(n);
		vector<int> query(m);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> query[i];
		}
		vector<int> ans(m, 0);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (arr[j] % query[i] == 0)
				{
					ans[i]++;
				}
			}
		}
		printArr(ans);
	}
	return 0;
}