//如何花最少的钱购买蔬菜
//
//描述
//
//Rahul wanted to purchase vegetables mainly brinjal, carrotand tomato.There are N different 
//vegetable sellers in a line.Each vegetable seller sells all three vegetable items, 
//but at different prices.Rahul, obsessed by his nature to spend optimally, decided not to 
//purchase same vegetable from adjacent shops.Also, Rahul will purchase exactly one type of 
//vegetable item(only 1 kg) from one shop.Rahul wishes to spend minimum money buying vegetables 
//using this strategy.Help Rahul determine the minimum money he will spend.
//
//输入
//
//First line indicates number of test cases T.Each test case in its first line contains N 
//denoting the number of vegetable sellers in Vegetable Market.Then each of next N lines 
//contains three space separated integers denoting cost of brinjal, carrotand tomato per kg 
//with that particular vegetable seller.
//
//输出
//
//For each test case, output the minimum cost of shopping taking the mentioned conditions 
//into account in a separate line.
//
//Constraints:1 <= T <= 101 <= N <= 100000 Cost of each vegetable(brinjal / carrot / tomato) 
//per kg does not exceed 10 ^ 4
//
//	输入样例 1
//
//	1
//	3
//	1 50 50
//	50 50 50
//	1 50 50
//
//	输出样例 1
//
//	52
//
#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;
long long min(long long a, long long b)
{
	return a < b ? a : b;
}
vector<string> token(string data)
{
	vector<string> res;
	int index = data.find(' ');
	while (index != string::npos)
	{
		string str = data.substr(0, index);
		res.push_back(str);
		data = data.substr(index + 1);
		index = data.find(' ');
	}
	if (data != "")
	{
		res.push_back(data);		
	}
	return res;
}
vector<long long> convertData(string data)
{
	vector<long long> res;
	vector<string> dataToken = token(data);
	for (int i = 0; i < dataToken.size(); ++i)
	{
		res.push_back(atoi(dataToken[i].c_str()));
	}
	return res;
}
int main()
{
	string data, blank;
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		getline(cin, blank);
		vector<vector<long long>> seller(n, vector<long long>(3));
		for (int i = 0; i < n; ++i)
		{
			getline(cin, data);
			seller[i] = convertData(data);
		}
		//第i个商店买第j样蔬菜的情况下的最小花费
		vector<vector<long long>> dp(n, vector<long long>(3));
		long long ans = INT_MAX;
		dp[0] = seller[0];
		for (int i = 1; i < n; ++i)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + seller[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + seller[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + seller[i][2];
		}
		ans = min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
		cout << ans << endl;
	}
	return 0;
}