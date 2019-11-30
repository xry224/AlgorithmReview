//
//
//描述
//
//对给定的点集合构造KD树，要求如下：将方差最大的维度作为当前的分割维度，将数据集在分割维度上排序后
//的中位数作为分割点。程序要检索给定点对应的最近的K个点的坐标。
//
//输入
//
//输入第一行为测试用例个数，后面为测试用例，每一个用例包含三行，第一行为点集合
//（点之间用逗号隔开，两个坐标用空格隔开），第二行为检索的点，第三行为K值。
//
//输出
//
//输出每一个用例的最近K个点，按照距离从小到大的顺序打印。
//
//输入样例 1
//
//1
//3 5, 6 2, 5 8, 9 3, 8 6, 1 1, 2 9
//8.2 4.6
//2
//
//输出样例 1
//
//8 6, 9 3
//
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct Point
{
	double x;
	double y;
	double distace;
	Point()
	{

	}
	Point(double a, double b)
	{
		x = a;
		y = b;
	}
	bool operator < (const Point& a)const
	{
		return distace < a.distace;
	}
};
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
void convertData(vector<Point>& points, string data)
{
	vector<string> token = split(data, ',');
	for (int i = 0; i < token.size(); ++i)
	{
		vector<string> datas = split(token[i], ' ');
		double x, y;
		x = atof(datas[0].c_str());
		y = atof(datas[1].c_str());
		points.push_back(Point(x, y));
	}
}
int main()
{
	int T;
	string data, blank;
	cin >> T;
	while (T--)
	{
		getline(cin, blank);
		getline(cin, data);
		double centerX, centerY;
		int k;
		cin >> centerX >> centerY;
		cin >> k;
		vector<Point> points;
		//vector<pair<double, double>> ans;
		convertData(points, data);
		for (int i = 0; i < points.size(); ++i)
		{
			double x = points[i].x;
			double y = points[i].y;
			points[i].distace = sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));
		}
		sort(points.begin(), points.end());
		for (int i = 0; i < k; ++i)
		{
			if (i != 0)
			{
				cout << ",";
			}
			cout << points[i].x << " " << points[i].y;
		}
		cout << endl;
	}
	return 0;
}