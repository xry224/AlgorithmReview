/*


描述

In a given cartesian plane, there are N points. We need to find the Number of Pairs of points(A,B) such that

	Point A and Point B do not coincide.
	Manhattan Distance and the Euclidean Distance between the points should be equal.

Note : Pair of 2 points(A,B) is considered same as Pair of 2 points(B,A).

Manhattan Distance = |x2-x1|+|y2-y1|

Euclidean Distance = ((x2-x1)^2 + (y2-y1)^2)^0.5 where points are (x1,y1) and (x2,y2).

Constraints:1<=T <= 50, 1<=N <= 2*10 ^ 5, 0<=(|Xi|, |Yi|) <= 10^9

输入

First Line Consist of T - number of test cases. For each Test case:First Line consist of N , Number of points. Next line contains N pairs contains two integers Xi and Yi，i.e, X coordinate and the Y coordinate of a Point

输出

Print the number of pairs as asked above.

输入样例 1

1
2
1 1
7 5

输出样例 1

0


*/
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
double ManhattanDistance(pair<int, int> pointA, pair<int, int> pointB)
{
	return abs(pointB.first - pointA.first) + abs(pointB.second - pointA.second);
}
double EuclideanDistance(pair<int, int> pointA, pair<int, int> pointB)
{
	int disX = pointB.first - pointA.first;
	int disY = pointB.second - pointA.second;
	return sqrt(disX * disX + disY * disY);
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		using pointPair = pair<pair<int, int>, pair<int, int>>;
		vector<pair<int, int>> points;
		map<pointPair, bool> appear;
		map<pair<int, int>, bool> exist;
		//当且仅当两点位于与坐标轴平行的直线上时，欧拉距离与曼哈顿距离相等
		for (int i = 0; i < n; ++i)
		{
			int x, y;
			cin >> x >> y;
			pair<int, int> point = make_pair(x, y);
			if (!exist[point])
			{
				points.push_back(point);
				exist[point] = true;
			}
		}
		int ans = 0;
		for (int i = 0; i < points.size(); ++i)
		{
			for (int j = i + 1; j < points.size(); ++j)
			{
				//pointPair curPair = make_pair(points[i], points[j]);
				//pointPair curRevPair = make_pair(points[j], points[i]);
				//if (appear[curPair])
				//{
				//	continue;
				//}
				if (points[i].first == points[j].first || points[i].second == points[j].second)
				{
					ans++;
					//appear[curPair] = true;
					//appear[curRevPair] = true;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}