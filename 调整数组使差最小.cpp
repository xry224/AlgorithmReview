//
//
//描述
//
//有两个序列 a, b，大小都为 n, 序列元素的值任意整数，无序； 要求：通过交换 a, b 中的元素，使[序列 a 元素的和]与[序列 b 元素的和]之间的差最小。
//
//输入
//
//输入第一行为用例个数， 每个测试用例输入为两行，分别为两个数组，每个值用空格隔开。
//
//输出
//
//输出变化之后的两个数组内元素和的差绝对值。
//
//输入样例 1
//
//1
//100 99 98 1 2 3
//1 2 3 4 5 40
//
//输出样例 1
//
//48
#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;
vector<string> dataToken(string data)
{
	vector<string> res;
	string str = data;
	int index = data.find(' ');
	while (index != string::npos)
	{
		res.push_back(str.substr(0, index));
		str = str.substr(index + 1);
		index = str.find(' ');
	}
	//！！输入数据可能存在问题！！
	if (str != "")
	{
		res.push_back(str);
	}
	return res;
}
void convertData(string data1, string data2, vector<int>& arr)
{
	vector<string> token1 = dataToken(data1);
	vector<string> token2 = dataToken(data2);
	for (int i = 0; i < token1.size(); ++i)
	{
		arr.push_back(atoi(token1[i].c_str()));
	}
	for (int i = 0; i < token2.size(); ++i)
	{
		arr.push_back(atoi(token2[i].c_str()));
	}
}
void dfs(vector<int> arr, int cnt1, int cnt2, int index, int& ans, int sum1, int sum2)
{
	if (cnt1 + cnt2 == arr.size())
	{
		if (abs(sum1 - sum2) < ans && cnt1 == cnt2)
		{
			ans = abs(sum1 - sum2);
		}
		return;
	}
	//剩余元素数量无法填补两个数组之间元素数量的差距
	if (abs(cnt1 - cnt2) > arr.size() - index)
	{
		return;
	}
	//将第index个数字分给第一个数组
	dfs(arr, cnt1 + 1, cnt2, index + 1, ans, sum1 + arr[index], sum2);
	dfs(arr, cnt1, cnt2 + 1, index + 1, ans, sum1, sum2 + arr[index]);
}
int main()
{
	int T;
	cin >> T;
	string blank;
	getline(cin, blank);
	while (T--)
	{
		string data1, data2;
		getline(cin, data1);
		getline(cin, data2);
		vector<int> arr;
		convertData(data1, data2, arr);
		int ans = INT_MAX;
		dfs(arr, 0, 0, 0, ans, 0, 0);
		cout << ans << endl;
	}
	return 0;
}