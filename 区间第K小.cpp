//
//
//描述
//
//找到给定数组的给定区间内的第K小的数值。
//
//输入
//
//输入第一行为用例个数， 每个测试用例输入的第一行为数组，每一个数用空格隔开；第二行是区间（第几个数到第几个数，两头均包含），两个值用空格隔开；第三行为K值。
//
//输出
//
//结果。
//
//输入样例 1
//
//1
//1 2 3 4 5 6 7
//3 5
//2
//
//输出样例 1
//
//4
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
	string data, blank;
	while (T--)
	{
		getline(cin, blank);
		getline(cin, data);
		int left, right, k;
		cin >> left >> right >> k;
		vector<int> arr;
		convertData(data, arr);
		//[a, b)
		sort(arr.begin() + left - 1, arr.begin() + right);
		int index = left + k - 2;
		cout << arr[index] << endl;
	}
	return 0;
}