//
//
//描述
//
//给定两个字符串，返回两个字符串的最长公共子序列（不是最长公共子字符串），可能是多个。
//
//输入
//
//输入第一行为用例个数， 每个测试用例输入为两行，一行一个字符串
//
//输出
//
//如果没有公共子序列，不输出，如果有多个则分为多行，按字典序排序。
//
//输入样例 1
//
//1
//1A2BD3G4H56JK
//23EFG4I5J6K7
//
//输出样例 1
//
//23G456K
//23G45JK
//
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
void solve(vector<vector<int>>& trace, string str1, string str2)
{
	int length1 = str1.size();
	int length2 = str2.size();
	//0:相同
	//1:str1
	//2:str2
	//3:两者均走
	vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1));
	for (int i = 1; i <= length1; ++i)
	{
		for (int j = 1; j <= length2; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				trace[i][j] = 0;
			}
			else
			{
				if (dp[i - 1][j] > dp[i][j - 1])
				{
					dp[i][j] = dp[i - 1][j];
					trace[i][j] = 1;
				}
				else if (dp[i - 1][j] < dp[i][j - 1])
				{
					dp[i][j] = dp[i][j - 1];
					trace[i][j] = 2;
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
					trace[i][j] = 3;
				}
			}
		}
	}
}
void getPath(vector<vector<int>> trace, string str1, string str2, string cur, set<string>& ans, int index1, int index2)
{
	//cout << index1 << " " << index2 <<" "<<trace[index1][index2]<< endl;
	if (index1 == 0 || index2 == 0)
	{
		reverse(cur.begin(), cur.end());
		ans.insert(cur);
		return;
	}
	switch (trace[index1][index2])
	{
	case 0:
	{
		cur += str1[index1 - 1];
		getPath(trace, str1, str2, cur, ans, index1 - 1, index2 - 1);
		break;
	}
	case 1:
	{
		getPath(trace, str1, str2, cur, ans, index1 - 1, index2);
		break;
	}
	case 2:
	{
		getPath(trace, str1, str2, cur, ans, index1, index2 - 1);
		break;
	}
	case 3:
	{
		getPath(trace, str1, str2, cur, ans, index1 - 1, index2);
		getPath(trace, str1, str2, cur, ans, index1, index2 - 1);
		break;
	}
	default:
		break;
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string str1, str2;
		cin >> str1 >> str2;
		int length1 = str1.length();
		int length2 = str2.length();
		vector<vector<int>> trace(length1 + 1, vector<int>(length2 + 1, -1));
		solve(trace, str1, str2);
		set<string> ans;
		getPath(trace, str1, str2, "", ans, length1, length2);
		for (string res : ans)
		{
			cout << res << endl;
		}
	}
	return 0;
}