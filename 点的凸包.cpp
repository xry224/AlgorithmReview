/*


����

Convex Hull of a set of points, in 2D plane, is a convex polygon with minimum area such that each 
point lies either on the boundary of polygon or inside it. 
Now given a set of points the task is to find the convex hull of points.

����

The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Each test case contains an integer N denoting the no of points. 
Then in the next line are N*2 space separated values denoting the points ie x and y.
Constraints:1<=T<=100,1<=N<=100,1<=x,y<=1000

���

For each test case in a new line print the points x and y of the convex hull separated by 
a space in sorted order (increasing by x) where every pair is separated from the other by a ','. 
If no convex hull is possible print -1.

�������� 1

2
3
1 2 3 1 5 6
3
1 2 4 4 5 1

������� 1

1 2, 3 1, 5 6
1 2, 4 4, 5 1


*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point
{
	long long x = 0;
	long long y = 0;
	long double polar = 0;
	Point(long long a, long long b)
	{
		x = a;
		y = b;
	}
	Point()
	{

	}
};
Point basePoint;
bool cmp(Point a, Point b)
{
	return a.x < b.x;
}
//��y��С�ģ�y��ͬ����x��С��
int findMin(vector<Point>& arr)
{
	int ans = 0;
	for (int i = 1; i < arr.size(); ++i)
	{
		if (arr[i].y < arr[ans].y || (arr[i].y == arr[ans].y) && (arr[i].x < arr[ans].x))
		{
			ans = i;
		}
	}
	return ans;
}
//�������������нǵ�����ֵ
long double calPolar(Point v1, Point v2)
{
	return (double)v1.x / (sqrt(v1.x * v1.x + v1.y * v1.y) * sqrt(v2.x * v2.x + v2.y * v2.y));
}
long double distance(Point a, Point basePoint)
{
	return sqrt((a.x - basePoint.x) * (a.x - basePoint.x) + (a.y - basePoint.y) * (a.y - basePoint.y));
}
//����ֵԽ������x��н�ԽС
bool cmpPolar(Point a, Point b)
{
	double dis1 = sqrt((a.x - 1) * (a.x - 1) + a.y * a.y);
	double dis2 = sqrt((b.x - 1) * (b.x - 1) + b.y * b.y);
	double dis3 = distance(a, basePoint);
	double dis4 = distance(b, basePoint);
	//�Ƕ���ͬ�����һ������ɵ�������ģ�Ĵ�С���� - > WA�ˣ�Ҫ�����(1,0)�Ĵ�С
	//����δ���
	if (a.polar == b.polar)
	{
		return dis1 < dis2;
	}
	return a.polar > b.polar;
}
//�������һ���� A �⣬ÿ������ A ���γɵ�����v1��x��ļнǵĴ�С
void sortByPolar(vector<Point>& arr)
{
	Point base = arr[0];
	basePoint = arr[0];
	//cout << "Base: " << endl << base.x << " " << base.y << endl;
	Point vecBase(1, 0);
	for (int i = 1; i < arr.size(); ++i)
	{
		Point vecCur(arr[i].x - base.x, arr[i].y - base.y);
		//�з���
		arr[i].polar = calPolar(vecCur, vecBase);
		//arr[i].dis = sqrt(vecCur.x * vecCur.x + vecCur.y * vecCur.y);
	}
	//
	sort(arr.begin() + 1, arr.end(), cmpPolar);
}
void printArr(vector<Point>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		if (i == 0)
		{
			cout << arr[i].x << " " << arr[i].y;
		}
		else
		{
			cout << ", " << arr[i].x << " " << arr[i].y;
		}
	}
	cout << endl;
}
//��˴���0������aλ��b�·�����֮Ϊ�Ϸ��������ԭ�㣬a��b˳ʱ�뷽��
long long cross(Point a, Point b)
{
	long long x = a.x * b.y;
	long long y = b.x * a.y;
	return x - y;
}
//�¼����c����һ���ڵ�b�γɵ�����v1������һ���ڵ�b�Լ�����һ���ڵ�a�γɵ�����v2
//�ж�v1�ķ����Ƿ�Ϊv2��ת
bool turnLeft(Point top, Point second, Point newP)
{
	Point vec1(newP.x - top.x, newP.y - top.y);
	Point vec2(top.x - second.x, top.y - second.y);
	if (cross(vec1, vec2) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void solve(vector<Point>& ans, vector<Point>& pointSet)
{
	ans.push_back(pointSet[0]);
	ans.push_back(pointSet[1]);
	//printArr(pointSet);
	for (int i = 2; i < pointSet.size(); ++i)
	{
		while (ans.size() >= 2 && !turnLeft(ans[ans.size() - 1], ans[ans.size() - 2], pointSet[i]))
		{
			ans.pop_back();
		}
		ans.push_back(pointSet[i]);
	}
}
void readFile(vector<Point>& points)
{
	fstream f;
	f.open("1.in", ios::in);
	if (f.is_open())
	{
		for (int i = 0; i < points.size() && !f.eof(); ++i)
		{
			f >> points[i].x >> points[i].y;
		}
	}
	f.close();
}	
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<Point> points(n);
		if (n < 3)
		{
			cout << -1 << endl;
			continue;
		}
		int minIndex = findMin(points);
		swap(points[minIndex], points[0]);
		sortByPolar(points);
	
		vector<Point> ans;
		solve(ans, points);
		sort(ans.begin(), ans.end(), cmp);
		if (ans.size() < 3)
		{
			cout << -1 << endl;
			continue;
		}
		printArr(ans);
	}
	return 0;
}