//
//
//描述
//
//输入一个数组和一个数字，在数组中查找两个数，使得它们的和正好是输入的那个数字，统计这样两个数的对数。
//
//输入
//
//输入第一行为用例个数， 每个测试用例输入第一行是数组，每一个数用空格隔开；第二行是数字和。
//
//输出
//
//输出这样两个数有几对。
//
//输入样例 1
//
//1
//1 2 4 7 11 0 9 15
//11
//
//输出样例 1
//
//3
//
#include <iostream>
#include <vector>
#include <string>
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
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string blank, data;
		getline(cin, blank);
		getline(cin, data);
		int sum;
		cin >> sum;
		vector<int> arr;
		convertData(data, arr);
		int cnt = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			for (int j = i + 1; j < arr.size(); ++j)
			{
				if (arr[i] + arr[j] == sum)
				{
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}