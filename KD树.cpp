//
//
//����
//
//�Ը����ĵ㼯�Ϲ���KD����Ҫ�����£�����������ά����Ϊ��ǰ�ķָ�ά�ȣ������ݼ��ڷָ�ά���������
//����λ����Ϊ�ָ�㡣����Ҫ�����������Ӧ�������K��������ꡣ
//
//����
//
//�����һ��Ϊ������������������Ϊ����������ÿһ�������������У���һ��Ϊ�㼯��
//����֮���ö��Ÿ��������������ÿո���������ڶ���Ϊ�����ĵ㣬������ΪKֵ��
//
//���
//
//���ÿһ�����������K���㣬���վ����С�����˳���ӡ��
//
//�������� 1
//
//1
//3 5, 6 2, 5 8, 9 3, 8 6, 1 1, 2 9
//8.2 4.6
//2
//
//������� 1
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