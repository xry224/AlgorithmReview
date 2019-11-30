//
//
//描述
//
//有一个由N个实数构成的数组，如果一对元素A[i]和A[j]是倒序的，即i<j但是A[i]>A[j]则称它们是一个倒置，
//设计一个计算该数组中所有倒置数量的算法。要求算法复杂度为O(nlogn)
//
//输入
//
//输入有多行，第一行整数T表示为测试用例个数，后面是T个测试用例，每一个用例包括两行，
//第一行的一个整数是元素个数，第二行为用空格隔开的数组值。
//
//输出
//
//输出每一个用例的倒置个数，一行表示一个用例。
//
//输入样例 1
//
//1
//8
//8 3 2 9 7 1 5 4
//
//输出样例 1
//
//17
//
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr, int left, int mid, int right, int& ans)
{
	int first = left;
	int second = mid + 1;
	vector<int> temp;
	while (first <= mid && second <= right)
	{
		//注意：是小于等于不是小于
		if (arr[first] <= arr[second])
		{
			temp.push_back(arr[first++]);
		}
		else
		{
			temp.push_back(arr[second++]);
			//int cnt = mid - left + 1;
			ans += mid - first + 1;
		}
	}
	while (first <= mid)
	{
		//temp.push_back(arr[first++]);
		temp.push_back(arr[first++]);
	}
	while (second <= right)
	{
		//temp.push_back(arr[second++]);
		temp.push_back(arr[second++]);
	}
	for (int i = 0; i < temp.size(); ++i)
	{
		arr[i + left] = temp[i];
	}
}
void merge(vector<int>& a, vector<int>& b, int start, int mid, int end, int& ans)
{
	int l = start, m = mid + 1, r = end, lb = start;
	while (l <= mid && m <= end)
	{
		if (a[l] <= a[m])
		{
			b[lb++] = a[l++];
		}
		else
		{
			b[lb++] = a[m++];
			ans += mid - l + 1;
		}
	}
	while (l < mid + 1)
		b[lb++] = a[l++];
	while (m < end + 1)
		b[lb++] = a[m++];
	for (int i = start; i <= end; i++)
	{
		a[i] = b[i];
	}
}
void mergeSort(vector<int>& arr, int left, int right, int& ans)
{
	if (left >= right)
	{
		return;
	}
	vector<int> t(arr.size());
	int mid = (left + right) / 2;
	mergeSort(arr, left, mid, ans);
	mergeSort(arr, mid + 1, right, ans);
	merge(arr, left, mid, right, ans);
}
int main()
{
	int T;
	int n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		int ans = 0;
		mergeSort(arr, 0, arr.size() - 1, ans);
		cout << ans << endl;	
	}
	return 0;
}