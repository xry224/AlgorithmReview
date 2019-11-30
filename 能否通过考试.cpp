//
//
//描述
//
//小张想要通过明天的考试。他知道考题的分值分布，也知道考试中要拿到每一个题目需要耗费的时间。假设考试时长为h，共n个题目，需要拿到p分才能通过考试。现在已知每个考题的得分与耗时，请你判断小张能否通过合理安排时间，而通过考试，并给出通过考试的最短时间。
//
//输入
//
//输入第一行为测试用例个数.每一个用例有若干行，第一行为任务数量n、考试时常h、通过分数p，下面的n行是每一个题目的耗时和得分。所有数值用空格分开。
//
//输出
//
//对每一个用例输出一行，如果能够通过考试，则输出“YES”和消耗最短时间，用空格隔开。 否则，输出“NO”。
//
//输入样例 1
//
//1
//5 40 21
//12 10
//16 10
//20 10
//24 10
//8 3
//
//输出样例 1
//
//YES 36
//
//2019.11.26 第三题
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, h, p;
		cin >> n >> h >> p;
		using costScore = pair<int, int>;
		vector<costScore> arr(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> arr[i].first >> arr[i].second;
		}
		vector<vector<int>> dp(n + 1, vector<int>(h + 1));
		int ans = INT_MAX;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = h; j >= arr[i].first; --j)
			{
				dp[i][j] = max(dp[i - 1][j - arr[i].first] + arr[i].second, dp[i - 1][j]);
				if (dp[i][j] >= p)
				{
					ans = ans > j ? j : ans;
				}
			}
		}
		if (ans == INT_MAX)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES " << ans << endl;
		}
	}
	return 0;
}