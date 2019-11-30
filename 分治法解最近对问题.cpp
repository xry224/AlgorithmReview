//
//
//����
//
//��������⣺ʹ�÷����㷨�����������⡣
//
//����
//
//��һ��Ϊ������������������ÿһ�б�ʾһ��������һ������ΪһЩƽ���ϵ�ļ��ϣ������֮���ö��Ÿ�����һ��������������ÿո����������ֵ����������
//
//���
//
//��ÿһ���������������������ĵ㣨����ʹ�ÿո���������ö��Ÿ������Ȱ��յ�һ�������С���У��ٰ��յڶ��������С���С�����ж���⣬����ÿ����ĵ�һ������������������������⣬�ö��Ÿ�����
//
//�������� 1
//
//1
//1 1, 2 2, 3 3, 4 4, 5 5, 1.5 1.5
//
//������� 1
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