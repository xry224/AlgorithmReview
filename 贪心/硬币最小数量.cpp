//
//
//描述
//
//Given the list of coins of distinct denominationsand total amount of money.Output the minimum number of coins required to make up that amount.Output - 1 if that money cannot be made up using given coins.You may assume that there are infinite numbers of coins of each type.
//
//输入
//
//The first line contains 'T' denoting the number of test cases.Then follows description of test cases.Each cases begins with the two space separated integers 'n' and 'amount' denoting the total number of distinct coins and total amount of money respectively.The second line contains N space - separated integers A1, A2, ..., AN denoting the values of coins.
//
//Constraints:1 <= T <= 30，1 <= n <= 100，1 <= Ai <= 1000，1 <= amount <= 100000
//
//输出
//
//Print the minimum number of coins required to make up that amount or return -1 if it is impossible to make that amount using given coins.
//
//输入样例 1
//
//2
//3 11
//1 2 5
//2 7
//2 6
//
//输出样例 1
//
//3
//- 1
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, amount;
		cin >> n >> amount;
		vector<int> coins(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> coins[i];
		}
		sort(coins.begin(), coins.end(), [](int a, int b) {return a > b; });
		int cnt = 0;
		for (int i = 0; i < coins.size(); ++i)
		{
			while (amount >= coins[i])
			{
				amount -= coins[i];
				cnt++;
			}
		}
		if (amount != 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << cnt << endl;
		}

	}
	return 0;
}