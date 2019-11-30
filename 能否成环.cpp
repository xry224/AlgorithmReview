//
//
//描述
//
//Given an array of strings A[ ], determine if the strings can be chained together to form a circle. A string X can be chained together with another string Y if the last character of X is same as first character of Y. If every string of the array can be chained, it will form a circle. For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf".
//
//输入
//
//The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
//
//The first line of each test case contains a positive integer N, denoting the size of the array.
//
//The second line of each test case contains a N space seprated strings, denoting the elements of the array A[ ].
//
//1 <= T
//
//0 < N
//
//0 < A[i]
//
//输出
//
//If chain can be formed, then print 1, else print 0.
//
//输入样例 1
//
//2
//3
//abc bcd cdf
//4
//ab bc cd da
//
//输出样例 1
//
//0
//1
//
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
void dfs(vector<string>& data, vector<bool>& visit, int layer, bool& flag, char preChar, string first)
{
	if (layer == data.size() || flag)
	{
		//全部入队后要检查最后一个元素能否和首元素连起来
		if (first[0] == preChar)
		{
			flag = true;
		}

		return;
	}
	for (int i = 0; i < data.size(); ++i)
	{
		if (!visit[i] && (preChar == ' ' || preChar == data[i][0]))
		{
			visit[i] = true;
			if (first == "")
			{
				dfs(data, visit, layer + 1, flag, data[i][data[i].size() - 1], data[i]);
			}
			else
			{
				dfs(data, visit, layer + 1, flag, data[i][data[i].size() - 1], first);
			}
			visit[i] = false;
		}
	}
}
bool special(vector<string>& sp)
{
	char cur = sp[0][0];
	for (int i = 0; i < sp.size(); ++i)
	{
		if (sp[i][0] != cur || sp[i][sp[i].size() - 1] != cur)
		{
			return false;
		}
	}
	return true;
}
//此解法不能A
void solve(vector<string>& strings, bool& flag)
{
	map<char, int> head;
	map<char, int> tail;
	vector<string> sp;
	for (int i = 0; i < strings.size(); ++i)
	{
		char first = strings[i][0];
		char last = strings[i][strings[i].size() - 1];
		if (first == last)
		{
			sp.push_back(strings[i]);
		}
		else
		{
			head[first]++;
			tail[last]++;
		}
	}
	map<char, int>::iterator it;
	if (head.size() == 0 && tail.size() == 0)
	{
		flag = special(sp);
		return;
	}
	for (it = head.begin(); it != head.end(); it++)
	{
		char cur = it->first;
		if (tail[cur] != it->second)
		{
			flag = false;
			return;
		}
	}
	for (int i = 0; i < sp.size(); ++i)
	{
		char cur = sp[i][0];
		if (head[cur] == 0)
		{
			flag = false;
			return;
		}
	}
	flag = true;

}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		bool flag = false;
		cin >> n;
		vector<string> strings(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> strings[i];
		}
		//仅一个元素算环
		if (n == 1)
		{
			if (strings[0][0] == strings[0][strings[0].size() - 1])
				cout << 1 << endl;
			else
				cout << 0 << endl;
			continue;
		}
		vector<bool> visit(n);
		dfs(strings, visit, 0, flag, ' ', "");
		//solve(strings, flag);
		if (flag)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	return 0;
}