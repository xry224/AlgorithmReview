//
//
//����
//
//��һ����N��ʵ�����ɵ����飬���һ��Ԫ��A[i]��A[j]�ǵ���ģ���i<j����A[i]>A[j]���������һ�����ã�
//���һ����������������е����������㷨��Ҫ���㷨���Ӷ�ΪO(nlogn)
//
//����
//
//�����ж��У���һ������T��ʾΪ��������������������T������������ÿһ�������������У�
//��һ�е�һ��������Ԫ�ظ������ڶ���Ϊ�ÿո����������ֵ��
//
//���
//
//���ÿһ�������ĵ��ø�����һ�б�ʾһ��������
//
//�������� 1
//
//1
//8
//8 3 2 9 7 1 5 4
//
//������� 1
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
		//ע�⣺��С�ڵ��ڲ���С��
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