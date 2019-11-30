//
//
//描述
//
//Given an array of N distinct elementsA[], find the minimum number of swaps required to sort the array.Your are required to complete the function which returns an integer denoting the minimum number of swaps, required to sort the array.
//
//输入
//
//The first line of input contains an integer T denoting the no of test cases.Then T test cases follow.Each test case contains an integer N denoting the no of element of the array A[].In the next line are N space separated values of the array A[] .(1 <= T <= 100; 1 <= N <= 100; 1 <= A[] <= 1000)
//
//输出
//
//For each test case in a new line output will be an integer denoting minimum umber of swaps that are required to sort the array.
//
//输入样例 1
//
//2
//4
//4 3 2 1
//5
//1 5 4 3 2
//
//输出样例 1
//
//2
//2
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//AC
int minSwap(vector<int>& arr)
{
	vector<int> sarr = arr;
	int ans = 0;
	map<int, int> pos;
	int length = arr.size();
	sort(sarr.begin(), sarr.end());
	//求每个元素的正确位置
	for (int i = 0; i < length; ++i)
	{
		pos[sarr[i]] = i;
	}
	vector<bool> inPosition(length, false);
	for (int i = 0; i < length; ++i)
	{
		int target = pos[arr[i]];
		//已交换过，或其本身就在正确位置上
		if (target == i || inPosition[i])
		{
			continue;
		}
		int incre = 0;
		int j = i;
		//归位
		while (!inPosition[j])
		{
			//当前位置被归位
			inPosition[j] = true;
			incre++;
			//获取交换后，被交换元素所处位置
			j = pos[arr[j]];
		}
		ans += incre - 1;
	}
	return ans;
}
//AC
int minSwaps(vector<int>& arr)
{
	vector<int> sarr = arr;
	int ans = 0;
	map<int, int> pos;
	int length = arr.size();
	sort(sarr.begin(), sarr.end());
	//求每个元素的正确位置
	for (int i = 0; i < length; ++i)
	{
		pos[sarr[i]] = i;
	}
	for (int i = 0; i < length; ++i)
	{
		int target = pos[arr[i]];
		if (target == i)
		{
			continue;
		}
		int cnt = 0;
		//归位直到当前位置元素的目标位置就是当前位置
		while (i != target)
		{
			//将当前元素放到目标位置
			swap(arr[i], arr[target]);
			//获取更换后当前位置元素的目标位置
			target = pos[arr[i]];
			cnt++;
		}
		ans += cnt;
	}
	return ans;
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
		cout << minSwaps(arr) << endl;
	}
	return 0;
}