//
//
//描述
//
//实现计数排序，通过多次遍历数组，统计比每一个元素小的其它元素个数，根据该统计量对数据进行排序。
//
//输入
//
//输入的每一行表示一个元素为正整数的数组，所有值用空格隔开，第一个值为数值长度，其余为数组元素值。
//
//输出
//
//输出的每一行为排序结果，用空格隔开，末尾不要空格。
//
//输入样例 1
//
//13 24 3 56 34 3 78 12 29 49 84 51 9 100
//
//输出样例 1
//
//3 3 9 12 24 29 34 49 51 56 78 84 100
//
#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;
void printArray(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		if (i == 0)
		{
			cout << arr[i];
		}
		else
		{
			cout << " " << arr[i];
		}
	}
	cout << endl;
}
vector<int> countSort(vector<int>& arr, int min, int max)
{
	int length = max - min + 1;
	//vector<int> count(length);
	map<int, int> count;
	vector<int> ans;
	for (int i = 0; i < arr.size(); ++i)
	{
		count[arr[i]]++;
	}
	map<int, int>::iterator it;
	for (it = count.begin(); it != count.end(); it++)
	{
		while ((*it).second > 0)
		{
			ans.push_back((*it).first);
			(*it).second--;
		}
	}
	return ans;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int min = INT_MAX;
		int max = INT_MIN;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			min = min < arr[i] ? min : arr[i];
			max = max > arr[i] ? max : arr[i];
		}
		arr = countSort(arr, min, max);
		printArray(arr);
	}
	return 0;
}