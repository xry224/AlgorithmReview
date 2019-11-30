/*
∆·π∑Œ›

√Ë ˆ

Dilpreet wants to paint his dog- Buzo's home that has n boards with different lengths[A1, A2,..., An]. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.The problem is to find the minimum time to get this job done under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

Constraints:1<=T<=100,1<=k<=30,1<=n<=50,1<=A[i]<=500

 ‰»Î

The first line consists of a single integer T, the number of test cases. For each test case, the first line contains an integer k denoting the number of painters and integer n denoting the number of boards. Next line contains n- space separated integers denoting the size of boards.

 ‰≥ˆ

For each test case, the output is an integer displaying the minimum time for painting that house.

 ‰»Î—˘¿˝ 1

2
2 4
10 10 10 10
2 4
10 20 30 40

 ‰≥ˆ—˘¿˝ 1

20
60
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int painters, homeSize;
		cin >> painters >> homeSize;
		int sum = 0;
		vector<int> dogHouse(homeSize);
		int low = 0;
		for (int i = 0; i < homeSize; ++i)
		{
			cin >> dogHouse[i];
			sum += dogHouse[i];
			low = low < dogHouse[i] ? dogHouse[i] : low;
		}
		for (int eachPaint = low; eachPaint <= sum; ++eachPaint)
		{
			int peopleCost = 0;
			int curCost = 0;
			for (int i = 0; i < homeSize; ++i)
			{
				if (curCost + dogHouse[i] <= eachPaint)
				{
					curCost += dogHouse[i];
				}
				else
				{
					curCost = dogHouse[i];
					peopleCost++;
				}
			}
			peopleCost++;
			if (peopleCost <= painters)
			{
				cout << eachPaint << endl;
				break;
			}
		}

	}
	return 0;
}