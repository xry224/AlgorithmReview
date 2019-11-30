//
//
//
//描述
//
//实现Shell排序，对给定的无序数组，按照给定的间隔变化（间隔大小即同组数字index的差），打印排序结果，注意不一定是最终排序结果！
//
//输入
//
//输入第一行表示测试用例个数，后面为测试用例，每一个用例有两行，第一行为给定数组，第二行为指定间隔，每一个间隔用空格隔开。
//
//输出
//
//输出的每一行为一个用例对应的指定排序结果。
//
//输入样例 1
//
//1
//49 38 65 97 76 13 27 49 55 4
//5 3
//
//输出样例 1
//
//13 4 49 38 27 49 55 65 97 76
//
//
//
//
#include <vector>
#include <iostream>
#include <string>
using namespace std;
vector<string> split(string data, char diff)
{
	vector<string> res;
	int index = data.find(diff);
	while (index != string::npos)
	{
		res.push_back(data.substr(0, index));
		data = data.substr(index + 1);
		index = data.find(diff);
	}
	if (data != "")
	{
		res.push_back(data);
	}
	return res;
}
void convertData(vector<int>& arr, string data)
{
	vector<string> token = split(data, ' ');
	for (int i = 0; i < token.size(); ++i)
	{
		arr.push_back(atoi(token[i].c_str()));
	}
}
void shellSort(vector<int>& arr, int interval)
{
	for (int i = 0; i < interval; ++i)
	{
		for (int j = i + interval; j < arr.size(); j += interval)
		{
			int key = arr[j];
			int pos = j - interval;
			while (pos >= 0 && arr[pos] > key)
			{
				arr[pos + interval] = arr[pos];
				pos -= interval;
			}
			arr[pos + interval] = key;
		}
	}
}
void printArray(vector<int> arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		if (i != 0)
		{
			cout << " ";
		}
		cout << arr[i];
	}
	cout << endl;
}
int main()
{
	int T;
	cin >> T;
	string blank;
	getline(cin, blank);
	while (T--)
	{
		string data, interval;
		getline(cin, data);
		getline(cin, interval);
		vector<int> arr;
		vector<int> inter;
		convertData(arr, data);
		convertData(inter, interval);
		for (int i = 0; i < inter.size(); ++i)
		{
			shellSort(arr, inter[i]);
		}
		printArray(arr);
	}
	return 0;
}