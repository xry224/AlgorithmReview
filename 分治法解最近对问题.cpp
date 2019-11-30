//
//
//描述
//
//最近对问题：使用分治算法解决最近对问题。
//
//输入
//
//第一行为测试用例个数。后面每一行表示一个用例，一个用例为一些平面上点的集合，点与点之间用逗号隔开，一个点的两个坐标用空格隔开。坐标值都是正数。
//
//输出
//
//对每一个用例输出两个距离最近的点（坐标使用空格隔开），用逗号隔开，先按照第一个坐标大小排列，再按照第二个坐标大小排列。如果有多个解，则按照每个解的第一个点的坐标排序，连续输出多个解，用逗号隔开。
//
//输入样例 1
//
//1
//1 1, 2 2, 3 3, 4 4, 5 5, 1.5 1.5
//
//输出样例 1
//
//1 1, 1.5 1.5, 1.5 1.5, 2 2
//
#include <iostream>
#include <vector>
#include <cfloat>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
struct Point
{
	double x;
	double y;
	Point(double a = 0, double b = 0)
	{
		x = a;
		y = b;
	}
	bool operator < (Point a)
	{
		if (x == a.x)
		{
			return y < a.y;
		}
		return x < a.x;
	}
};
using pointPair = pair<Point, Point>;
vector<string> split(string data, char diff)
{
	vector<string> res;
	int index = data.find(diff);
	while (index != string::npos)
	{
		res.push_back(data.substr(0, index));
		data = data.substr(index + 1);
		index = data.find(diff);
	}
	if (data != "")
	{
		res.push_back(data);
	}
	return res;
}
void convertData(vector<Point>& sets, string data)
{
	vector<string> token = split(data, ',');
	for (int i = 0; i < token.size(); ++i)
	{
		vector<string> datas = split(token[i], ' ');
		double x = atof(datas[0].c_str());
		double y = atof(datas[1].c_str());
		sets.push_back(Point(x, y));
	}
}
bool cmp(pointPair a, pointPair b)
{
	return a.first < b.first;
}
double distance(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
	int T;
	cin >> T;
	string data, blank;
	getline(cin, blank);
	while (T--)
	{
		getline(cin, data);
		vector<Point> pointSet;
		convertData(pointSet, data);
		vector<pointPair> ans;
		double minAns = DBL_MAX;
		sort(pointSet.begin(), pointSet.end());
		for (int i = 0; i < pointSet.size(); ++i)
		{
			for (int j = i + 1; j < pointSet.size(); ++j)
			{
				double dis = distance(pointSet[i], pointSet[j]);
				if (dis < minAns)
				{
					minAns = dis;
					ans.clear();
					ans.push_back(make_pair(pointSet[i], pointSet[j]));
				}
				//cout << dis << " " << minAns << endl;
				else if (dis == minAns)
				{
					ans.push_back(make_pair(pointSet[i], pointSet[j]));
				}
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		for (int i = 0; i < ans.size(); ++i)
		{
			if (i != 0)
			{
				cout << ",";
			}
			cout << ans[i].first.x << " " << ans[i].first.y << "," << ans[i].second.x << " " << ans[i].second.y;
		}
		cout << endl;
	}
	return 0;
}