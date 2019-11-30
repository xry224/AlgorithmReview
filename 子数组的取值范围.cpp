//
//
//描述
//
//给定数组arr和整数num，求arr的连续子数组中满足：其最大值减去最小值的结果大于num的个数。请实现一个时间复杂度为O(length(arr))的算法。
//
//输入
//
//输入第一行为测试用例个数。每一个用例有若干行，第一行为数组，每一个数用空格隔开，第二行为num。
//
//输出
//
//输出一个值。
//
//输入样例 1
//
//1
//3 6 4 3 2
//2
//
//输出样例 1
//
//6
//
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
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
void convertData(string data, vector<int>& arr)
{
	vector<string> strToken = dataToken(data);
	for (int i = 0; i < strToken.size(); ++i)
	{
		arr.push_back(atoi(strToken[i].c_str()));
	}
}
void solveBruce(vector<int> arr, int num)
{
	int ans = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		int min = arr[i];
		int max = arr[i];
		bool flag = false;
		for (int j = i + 1; j < arr.size(); ++j)
		{
			min = arr[j] < min ? arr[j] : min;
			max = arr[j] > max ? arr[j] : max;
			if (max - min > num)
			{
				ans += arr.size() - j;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			break;
		}
		
	}
	cout << ans << endl;
}
int main()
{
	int T;
	cin >> T;
	string data, blank;
	while (T--)
	{
		getline(cin, blank);
		int num;
		getline(cin, data);
		cin >> num;
		vector<int> arr;
		convertData(data, arr);
		solveBruce(arr, num);

	}
	return 0;
}