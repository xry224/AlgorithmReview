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
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int solve(vector<int> arrival, vector<int> leave)
{
	int cnt = 0;
	multimap<int, char> maps;
	//sort(arrival.begin(), arrival.end());
	for (int i = 0; i < arrival.size(); ++i)
	{
		maps.insert(make_pair(arrival[i], 'a'));
		maps.insert(make_pair(leave[i], 'd'));
	}
	multimap<int, char>::iterator it;
	int cur = 0;
	for (it = maps.begin(); it != maps.end(); it++)
	{
		pair<int, char> curStatus = *it;
		if (curStatus.second == 'a')
		{
			cur++;
		}
		else
		{
			cur--;
		}
		cnt = cnt < cur ? cur : cnt;
	}

	return  cnt;
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
		int ans = solve(arrival, leave);
		cout << ans << endl;
	}
	return 0;
}