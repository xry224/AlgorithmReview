// µœ÷√∞≈›≈≈–Ú
#include <iostream>
#include <string>
#include <vector>
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
void BubbleSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 0; j < arr.size() - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}
int main()
{
	string data;
	int n;
	while (cin >> n)
	{
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		BubbleSort(arr);
		printArray(arr);
	}
	return 0;
}