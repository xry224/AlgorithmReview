#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int findNeed(vector<int> arrival, vector<int> leave)
{
	int length = arrival.size();
	multimap<int, char> order;
	for (int i = 0; i < length; ++i)
	{
		int arr = arrival[i];
		int lea = leave[i];
		order.insert(make_pair(arr, 'a'));
		order.insert(make_pair(lea, 'd'));
	}
	int ans = 0;
	int curNeed = 0;
	multimap<int, char>::iterator it;
	for (it = order.begin(); it != order.end(); it++)
	{
		if ((*it).second == 'a')
		{
			curNeed++;
		}
		else
		{
			curNeed--;
		}
		ans = ans < curNeed ? curNeed : ans;
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
		vector<int> arrival(n);
		vector<int> leave(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arrival[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> leave[i];
		}
		cout << findNeed(arrival, leave) << endl;
	}
	return 0;
}