//
//
//����
//
//С����Ҫͨ������Ŀ��ԡ���֪������ķ�ֵ�ֲ���Ҳ֪��������Ҫ�õ�ÿһ����Ŀ��Ҫ�ķѵ�ʱ�䡣���迼��ʱ��Ϊh����n����Ŀ����Ҫ�õ�p�ֲ���ͨ�����ԡ�������֪ÿ������ĵ÷����ʱ�������ж�С���ܷ�ͨ��������ʱ�䣬��ͨ�����ԣ�������ͨ�����Ե����ʱ�䡣
//
//����
//
//�����һ��Ϊ������������.ÿһ�������������У���һ��Ϊ��������n������ʱ��h��ͨ������p�������n����ÿһ����Ŀ�ĺ�ʱ�͵÷֡�������ֵ�ÿո�ֿ���
//
//���
//
//��ÿһ���������һ�У�����ܹ�ͨ�����ԣ��������YES�����������ʱ�䣬�ÿո������ ���������NO����
//
//�������� 1
//
//1
//5 40 21
//12 10
//16 10
//20 10
//24 10
//8 3
//
//������� 1
//
//YES 36
//
//2019.11.26 ������
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