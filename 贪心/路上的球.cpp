//
//
//����
//
//There are two parallel roads, each containing Nand M buckets, respectively.Each bucket may contain some balls.The buckets on both roads are kept in such a way that they are sorted according to the number of balls in them.Geek starts from the end of the road which has the bucket with a lower number of balls(i.e. if buckets are sorted in increasing order, then geek will start from the left side of the road).The geek can change the road only at the point of intersection(which means, buckets with the same number of balls on two roads).Now you need to help Geek to collect the maximum number of balls.
//
//����
//
//The first line of input contains T denoting the number of test cases.The first line of each test case contains two integers Nand M, denoting the number of buckets on road1and road2 respectively. 2nd line of each test case contains N integers, number of balls in buckets on the first road. 3rd line of each test case contains M integers, number of balls in buckets on the second road.
//
//Constraints:1 <= T <= 1000��1 <= N <= 10 ^ 3��1 <= M <= 10 ^ 3��0 <= A[i], B[i] <= 10 ^ 6
//
//	���
//
//	For each test case output a single line containing the maximum possible balls that Geek can collect.
//
//	�������� 1
//
//	1
//	5 5
//	1 4 5 6 8
//	2 3 4 6 9
//
//	������� 1
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
	int i = 0;
	int j = 0;
	int sum1 = 0, sum2 = 0;
	int ans = 0;
	//�鲢�����˼��
	while (i < road1.size() && j < road2.size())
	{
		//����ڿ�ת����֮ǰ������·�Ϸֱ�����ֵ
		if (road1[i] < road2[j])
		{
			sum1 += road1[i];
			i++;
		}
		else if (road1[i] > road2[j])
		{
			sum2 += road2[j];
			j++;
		}
		else
		{
			sum1 += road1[i++];
			sum2 += road2[j++];
			//�׶���ͳ��
			ans += max(sum1, sum2);
			//�����ظ�����
			sum1 = sum2 = 0;
		}
	}
	while (i < road1.size())
	{
		sum1 += road1[i++];
	}
	while (j < road2.size())
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