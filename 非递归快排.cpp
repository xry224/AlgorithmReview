//
//
//描述
//
//快速排序的核心思想是使用元素的值对数组进行划分。实现其非递归方案。
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
#include <stack>
#include <queue>
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
int partition(vector<int>& arr, int left, int right)
{
	if (left >= right)
	{
		return -1;
	}
	int first = left;
	int second = right;
	int key = arr[first];
	while (first < second)
	{
		while (first < second && arr[second] >= key)
		{
			second--;
		}
		arr[first] = arr[second];
		while (first < second && arr[first] <= key)
		{
			first++;
		}
		arr[second] = arr[first];
	}
	arr[first] = key;
	return first;
}
void quickSort2(vector<int>& arr)
{
	queue<pair<int, int>> segment;
	segment.push(make_pair(0, arr.size() - 1));
	while (!segment.empty())
	{
		pair<int, int> curSeg = segment.front();
		segment.pop();
		if (curSeg.first < curSeg.second)
		{
			int mid = partition(arr, curSeg.first, curSeg.second);

			segment.push(make_pair(curSeg.first, mid-1));
			segment.push(make_pair(mid + 1, curSeg.second));
		}
	}
}
void quickSort(vector<int>& arr)
{
	stack<int> s;
	s.push(arr.size() - 1);
	s.push(0);
	while (!s.empty())
	{
		int first = s.top();
		s.pop();
		int second = s.top();
		s.pop();
		if (first < second)
		{
			int mid = partition(arr, first, second);
			//左区间
			s.push(mid - 1);
			s.push(first);
			//右区间
			s.push(second);
			s.push(mid + 1);
		}
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		quickSort2(arr);
		printArray(arr);
	}
	return 0;
}