//
//
//描述
//
//Given arrivaland departure times of all trains that reach a railway station.Your task is to find the minimum number of platforms required for the railway station so that no train waits.
//
//Note: Consider that all the trains arrive on the same dayand leave on the same day.Also, arrivaland departure times must not be same for a train.
//
//输入
//
//The first line of input contains T, the number of test cases.For each test case, first line will contain an integer N, the number of trains.Next two lines will consist of N space separated time intervals denoting arrivaland departure times respectively.
//
//Note: Time intervals are in the 24 - hourformat(hhmm), preceding zeros are insignificant. 200 means 2 : 00.
//	Consider the example for better understanding of input.
//
//	Constraints : 1 <= T <= 100，1 <= N <= 1000，1 <= A[i] < D[i] <= 2359
//
//	输出
//
//	For each test case, print the minimum number of platforms required for the trains to arriveand depart safely.
//
//	输入样例 1
//
//	1
//	6
//	900  940 950  1100 1500 1800
//	910 1200 1120 1130 1900 2000
//
//	输出样例 1
//
//	3
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int findPlatform(int arr[], int dep[], int n)
{
   // Sort arrival and departure arrays
   sort(arr, arr+n);
   sort(dep, dep+n);

   // plat_needed indicates number of platforms
   // needed at a time
   int plat_needed = 1, result = 1;
   int i = 1, j = 0;

   // Similar to merge in merge sort to process
   // all events in sorted order
   while (i < n && j < n)
   {
	  // If next event in sorted order is arrival,
	  // increment count of platforms needed
	  if (arr[i] <= dep[j])
	  {
		  plat_needed++;
		  i++;

		  // Update result if needed
		  if (plat_needed > result)
			  result = plat_needed;
	  }

	  // Else decrement count of platforms needed
	  else
	  {
		  plat_needed--;
		  j++;
	  }
   }

   return result;
}
int findPlatform(vector<int> arr, vector<int> dep, int n)
{
	// Insert all the times (arr. and dep.) 
	// in the multimap. 
	multimap<int, char> order;
	for (int i = 0; i < n; i++) {

		// If its arrival then second value 
		// of pair is 'a' else 'd' 
		order.insert(make_pair(arr[i], 'a'));
		order.insert(make_pair(dep[i], 'd'));
	}

	int result = 0;
	int plat_needed = 0;

	multimap<int, char>::iterator it = order.begin();

	// Start iterating the multimap. 
	for (; it != order.end(); it++) {

		// If its 'a' then add 1 to plat_needed 
		// else minus 1 from plat_needed. 
		if ((*it).second == 'a')
			plat_needed++;
		else
			plat_needed--;

		if (plat_needed > result)
			result = plat_needed;
	}
	return result;
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first < b.first;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<pair<int, int>> intervals(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> intervals[i].first;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> intervals[i].second;
		}
		sort(intervals.begin(), intervals.end(), cmp);
		int ans = 1;
		for (int time = 0; time <= 2400; ++time)
		{
			int cnt = 0;
			for (int i = 0; i < intervals.size(); ++i)
			{
				if (intervals[i].first <= time && intervals[i].second >= time)
				{
					cnt++;
				}
			}
			ans = ans < cnt ? cnt : ans;
		}
		cout << ans << endl;
	}
	return 0;
}