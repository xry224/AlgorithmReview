//
//
//描述
//
//There are two parallel roads, each containing Nand M buckets, respectively.Each bucket may contain some balls.The buckets on both roads are kept in such a way that they are sorted according to the number of balls in them.Geek starts from the end of the road which has the bucket with a lower number of balls(i.e. if buckets are sorted in increasing order, then geek will start from the left side of the road).The geek can change the road only at the point of intersection(which means, buckets with the same number of balls on two roads).Now you need to help Geek to collect the maximum number of balls.
//
//输入
//
//The first line of input contains T denoting the number of test cases.The first line of each test case contains two integers Nand M, denoting the number of buckets on road1and road2 respectively. 2nd line of each test case contains N integers, number of balls in buckets on the first road. 3rd line of each test case contains M integers, number of balls in buckets on the second road.
//
//Constraints:1 <= T <= 1000，1 <= N <= 10 ^ 3，1 <= M <= 10 ^ 3，0 <= A[i], B[i] <= 10 ^ 6
//
//	输出
//
//	For each test case output a single line containing the maximum possible balls that Geek can collect.
//
//	输入样例 1
//
//	1
//	5 5
//	1 4 5 6 8
//	2 3 4 6 9
//
//	输出样例 1
//
//	29
//
#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int solve(vector<int>& road1, vector<int>& road2)
{
	int ans = 0;
	int i = 0, j = 0;
	int length1 = road1.size();
	int length2 = road2.size();
	int sum1 = 0, sum2 = 0;
	while (i < length1 && j < length2)
	{
		if (road1[i] < road2[j])
		{
			sum1 += road1[i++];
		}
		else if (road1[i] > road2[j])
		{
			sum2 += road2[j++];
		}
		else
		{
			int commom = road1[i];
			sum1 += road1[i++];
			sum2 += road2[j++];
			ans += max(sum1, sum2);
			sum1 = sum2 = 0;
			while (i < length1 && road1[i] == commom)
			{
				sum1 += commom;
				i++;
			}
			while (j < length2 && road2[j] == commom)
			{
				sum2 += commom;
				j++;
			}
			ans += sum1 + sum2;
			sum1 = sum2 = 0;
		}

	}

	while (i < length1)
	{
		sum1 += road1[i++];
	}
	while (j < length2)
	{
		sum2 += road2[j++];
	}

	ans += max(sum1, sum2);
	return ans;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> road1(n);
		vector<int> road2(m);
		for (int i = 0; i < n; ++i)
		{
			cin >> road1[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> road2[i];
		}
		cout << solve(road1, road2) << endl;
	}
	return 0;
}