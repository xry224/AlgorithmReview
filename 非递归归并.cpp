//∑«µ›πÈπÈ≤¢≈≈–Ú
#include <iostream>
#include <vector>
#include <string>
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
void merge(vector<int>& arr, int left, int mid, int right)
{
	int i = left, j = mid + 1;
	vector<int> temp(arr.size());
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
		{
			temp[k++] = arr[i];
			i++;
		}
		else
		{
			temp[k++] = arr[j];
			j++;
		}
	}
	while (i <= mid)
	{
		temp[k++] = arr[i++];
	}
	while (j <= right)
	{
		temp[k++] = arr[j++];
	}
	for (int i = left; i <= right; ++i)
	{
		arr[i] = temp[i];
	}
}
void mergeSort(vector<int>& arr)
{
	int length = arr.size();
	for (int k = 1; k < arr.size(); k *= 2)
	{
		for (int i = 0; i < arr.size(); i += k * 2)
		{
			int left = i;
			int mid = i + k - 1 > length ? length - 1 : i + k - 1;
			int right = i + 2 * k - 1 > length ? length - 1 : i + 2 * k - 1;
			merge(arr, left, mid, right);
		}
	}
}
vector<string> token(string& data)
{
	vector<string> ans;
	string temp = "";
	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i] == ' ')
		{
			ans.push_back(temp);
			temp = "";
			continue;
		}
		temp += data[i];
	}
	if (temp != "")
	{
		ans.push_back(temp);
	}
	return ans;
}
void convertData(string& data, vector<int>& arr)
{
	vector<string> dataChunk = token(data);
	for (int i = 0; i < dataChunk.size(); ++i)
	{
		arr.push_back(stoi(dataChunk[i]));
	}
}
int main()
{
	int n;
	string data;
	while (cin >> n)
	{
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		mergeSort(arr);
		printArray(arr);
	}
	return 0;
}