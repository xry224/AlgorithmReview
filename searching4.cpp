/*


描述

Given n Magnets which are placed linearly, with each magnet to be considered as of point object. Each magnet suffers force from its left sided magnets such that they repel it to the right and vice versa. All forces are repulsive. The force being equal to the distance (1/d , d being the distance). Now given the positions of the magnets, the task to find all the points along the linear line where net force is ZERO.

Note: Distance have to be calculated with precision of 0.0000000000001.

Constraints:1<=T<=100,1<=N<=100,1<=M[]<=1000

输入

The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The second line of each test case contains an integer N. Then in the next line are N space separated values of the array M[], denoting the positions of the magnet.

输出

For each test case in a new line print the space separated points having net force zero till precised two decimal places.

输入样例 1

2
2
1 2
4
0 10 20 30

输出样例 1

1.50
3.82 15.00 26.18


*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#define PRECISION 0.0000000000001
long double calForce(long double pos, vector<long double>& magnet)
{
	long double force = 0;
	for (int i = 0; i < magnet.size(); ++i)
	{
		force += 1.0 / (pos - magnet[i]);
	}
	return force;
}
long double search(vector<long double>& ans, vector<long double>& magnet, long double low, long double high)
{
	long double mid = (low + high) / 2.0;
	long double force = calForce(mid, magnet);
	if (abs(force) < PRECISION)
	{
		return mid;
	}
	if (force > 0)
	{
		return search(ans, magnet, mid, high);
	}
	else
	{
		return search(ans, magnet, low, mid);
	}
}
void printArr(vector<long double>& ans)
{
	for (int i = 0; i < ans.size(); ++i)
	{
		if (i == 0)
		{
			cout << fixed << setprecision(2) << ans[i];
		}
		else
		{
			cout << " " << fixed << setprecision(2) << ans[i];
		}
	}
	cout << endl;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<long double> magnet(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> magnet[i];
		}
		vector<long double> ans;
		for (int i = 0; i < n - 1; ++i)
		{
			long double res = search(ans, magnet, magnet[i], magnet[i + 1]);
			ans.push_back(res);
		}
		printArr(ans);
	}
}