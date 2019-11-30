/*
描述

Given an array, the task is to complete the function which finds the maximum sum subarray, 
where you may remove at most one element to get the maximum sum.

输入

第一行为测试用例个数T；后面每两行表示一个用例，第一行为用例中数组长度N，第二行为数组具体内容。

输出

每一行表示对应用例的结果。

输入样例 1

1
5
1 2 3 -4 5

输出样例 1

11

*/
#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
void solve(vector<int>& arr)
{
	int length = arr.size();
	//正/逆序以第i个元素为结尾的最大子数组和
	//或者说直到i为之的最大子数组和以及从i开始的最大子数组和
	vector<int> dpForward(length);
	vector<int> dpBackward(length);
	dpForward[0] = arr[0];
	dpBackward[length - 1] = arr[length - 1];
	int curMax = arr[0];
	//正反序求最大子数组，求得的最大值即为不删除元素时的最大值
	for (int i = 1; i < length; ++i)
	{
		dpForward[i] = max(arr[i], arr[i] + dpForward[i - 1]);
		curMax = max(curMax, dpForward[i]);
	}
	for (int i = length - 2; i >= 0; i--)
	{
		dpBackward[i] = max(arr[i], arr[i] + dpBackward[i + 1]);
		curMax = max(curMax, dpBackward[i]);
	}
	
	//去掉第i个元素的情况
	for (int i = 1; i < length - 1; i++)
	{
		//cout << dpForward[i - 1] << " " << dpBackward[i + 1] << endl;
		curMax = max(curMax, dpForward[i - 1] + dpBackward[i + 1]);
	}
	cout << curMax << endl;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		//题意：先求出一个子数组，然后在这其中删掉一个元素或不删
		//求这样操作的最大子数组和
		solve(arr);
	}
	return 0;
}