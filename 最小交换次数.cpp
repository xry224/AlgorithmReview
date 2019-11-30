//
//
//����
//
//Given an array of N distinct elementsA[], find the minimum number of swaps required to sort the array.Your are required to complete the function which returns an integer denoting the minimum number of swaps, required to sort the array.
//
//����
//
//The first line of input contains an integer T denoting the no of test cases.Then T test cases follow.Each test case contains an integer N denoting the no of element of the array A[].In the next line are N space separated values of the array A[] .(1 <= T <= 100; 1 <= N <= 100; 1 <= A[] <= 1000)
//
//���
//
//For each test case in a new line output will be an integer denoting minimum umber of swaps that are required to sort the array.
//
//�������� 1
//
//2
//4
//4 3 2 1
//5
//1 5 4 3 2
//
//������� 1
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
	//��ÿ��Ԫ�ص���ȷλ��
	for (int i = 0; i < length; ++i)
	{
		pos[sarr[i]] = i;
	}
	vector<bool> inPosition(length, false);
	for (int i = 0; i < length; ++i)
	{
		int target = pos[arr[i]];
		//�ѽ����������䱾�������ȷλ����
		if (target == i || inPosition[i])
		{
			continue;
		}
		int incre = 0;
		int j = i;
		//��λ
		while (!inPosition[j])
		{
			//��ǰλ�ñ���λ
			inPosition[j] = true;
			incre++;
			//��ȡ�����󣬱�����Ԫ������λ��
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
	//��ÿ��Ԫ�ص���ȷλ��
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
		//��λֱ����ǰλ��Ԫ�ص�Ŀ��λ�þ��ǵ�ǰλ��
		while (i != target)
		{
			//����ǰԪ�طŵ�Ŀ��λ��
			swap(arr[i], arr[target]);
			//��ȡ������ǰλ��Ԫ�ص�Ŀ��λ��
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