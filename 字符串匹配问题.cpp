/*


描述

Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

输入

输入第一行是用例个数，后面一行表示一个用例；用例包括两部分，第一部分为给定文本，第二部分为搜索串，两部分使用","隔开。

输出

每一个用例输出一行，每行按照找到的位置先后顺序排列，使用空格隔开。

输入样例 1

2
THIS IS A TEST TEXT,TEST
AABAACAADAABAABA,AABA

输出样例 1

10
0 9 12


*/
#include <iostream>
#include <string>
#include <vector>
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
void solve(string& data, string& pattern, vector<int>& ans)
{
	int index = data.find(pattern);
	while (index != string::npos)
	{
		ans.push_back(index);
		index = data.find(pattern, index + 1);
	}
}
int main()
{
	int T;
	cin >> T;
	string data, blank;
	getline(cin, blank);
	while (T--)
	{
		getline(cin, data);
		int index = data.find(',');
		string pattern = data.substr(index + 1);
		string str = data.substr(0, index);
		vector<int> ans;
		solve(str, pattern, ans);
		printArr(ans);

	}
	return 0;
}