/*

描述

Given two array A1[] and A2[], sort A1 in such a way that the relative order among the elements will be same as those in A2. For the elements not present in A2. Append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.

Input:A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8} A2[] = {2, 1, 8, 3}Output: A1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}

Since 2 is present first in A2[], all occurrences of 2s should appear first in A[], then all occurrences 1s as 1 comes after 2 in A[]. Next all occurrences of 8 and then all occurrences of 3. Finally we print all those elements of A1[] that are not present in A2[]

Constraints:1 ≤ T ≤ 501 ≤ M ≤ 501 ≤ N ≤ 10 & N ≤ M1 ≤ A1[i], A2[i] ≤ 1000

输入

The first line of input contains an integer T denoting the number of test cases. The first line of each test case is M and N. M is the number of elements in A1 and N is the number of elements in A2.The second line of each test case contains M elements. The third line of each test case contains N elements.

输出

Print the sorted array according order defined by another array.

输入样例 1

1
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3

输出样例 1

2 2 1 1 8 8 3 5 6 7 9
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
void printArr(vector<int>& ans)
{
	for (int i = 0; i < ans.size(); ++i)
	{
		if (!i)
		{
			cout << ans[i];
		}
		else
		{
			cout << " " << ans[i];
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
		map<int, int> appear;
		vector<int> A2(m);
		vector<int> A1(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> A1[i];
			appear[A1[i]]++;
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> A2[i];
		}
		sort(A1.begin(), A1.end());
		vector<int> ans;
		for (int i = 0; i < m; ++i)
		{
			int cur = A2[i];
			while (appear[cur])
			{
				ans.push_back(cur);
				appear[cur]--;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (appear[A1[i]])
			{
				ans.push_back(A1[i]);
			}
		}
		printArr(ans);
	}
	return 0;
}

