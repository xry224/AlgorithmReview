/*


描述

Rahul and Ankit are the only two waiters in Royal Restaurant. Today, the restaurant received N orders. The amount of tips may differ when handled by different waiters, if Rahul takes the ith order, he would be tipped Ai rupees and if Ankit takes this order, the tip would be Bi rupees.In order to maximize the total tip value they decided to distribute the order among themselves. One order will be handled by one person only. Also, due to time constraints Rahul cannot take more than X orders and Ankit cannot take more than Y orders. It is guaranteed that X + Y is greater than or equal to N, which means that all the orders can be handled by either Rahul or Ankit. Find out the maximum possible amount of total tip money after processing all the orders.

输入

• The first line contains one integer, number of test cases.

• The second line contains three integers N, X, Y.

• The third line contains N integers. The ith integer represents Ai.

• The fourth line contains N integers. The ith integer represents Bi.

输出

Print a single integer representing the maximum tip money they would receive.

输入样例 1

1
5 3 3
1 2 3 4 5
5 4 3 2 1

输出样例 1

21

In the above problem we will use greedy approach to get the maximum tip earned by the two waiters. Following steps will help in solving this problem:
1.    Sort the absolute difference of the value of Ai and Bi( |Ai-Bi|) in decreasing order.
2.    Compare Ai and Bi value which one will be greater add that value to the sum.
3.    Decrement from the total order taken by Rahul or Ankit in case of order taken from A or B row by the comparison made.
4.    If i equals to n goto step 5 else goto step 2.
5.    Return sum.


*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool cmp(vector<int>& a, vector<int>& b)
{
	int dis1 = abs(a[1] - a[0]);
	int dis2 = abs(b[1] - b[0]);
	return dis1 > dis2;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, x, y;
		cin >> n >> x >> y;
		vector<vector<int>> tips(n, vector<int>(2));
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> tips[j][i];
			}
		}
		sort(tips.begin(), tips.end(), cmp);
		int ans = 0;
		int curX = 0;
		int curY = 0;
		for (int i = 0; i < n; ++i)
		{
			if (tips[i][0] > tips[i][1])
			{
				if (curX < x)
				{
					ans += tips[i][0];
					curX++;
				}
				else
				{
					ans += tips[i][1];
					curY++;
				}
			}
			else
			{
				if (curY < y)
				{
					ans += tips[i][1];
					curY++;
				}
				else
				{
					ans += tips[i][0];
					curX++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}