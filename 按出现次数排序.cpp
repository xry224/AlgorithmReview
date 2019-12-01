//
//
//描述
//
//对给定数组中的元素按照元素出现的次数排序，出现次数多的排在前面，如果出现次数相同，则按照数值大小排序。例如，给定数组为{ 2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12 }，则排序后结果为{ 3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5 }。
//
//输入
//
//输入的第一行为用例个数；后面每一个用例使用两行表示，第一行为数组长度，第二行为数组内容，数组元素间使用空格隔开。
//
//输出
//
//每一个用例的排序结果在一行中输出，元素之间使用空格隔开。
//
//输入样例 1
//
//1
//4
//2 3 2 5
//
//输出样例 1
//
//2 2 3 5
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct Node
{
	int val;
	int appear;
	Node(int var)
	{
		val = var;
		appear = 1;
	}
	bool operator < (const Node& a) const
	{
		if (a.appear == appear)
		{
			return val < a.val;
		}
		return appear > a.appear;
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<Node> ans;
		map<int, int> index;
		for (int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;
			if (index[num] == 0)
			{
				Node t = Node(num);
				
				ans.push_back(t);
				index[num] = ans.size();
			}
			else
			{
				ans[index[num] - 1].appear++;
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++i)
		{
			for (int j = 0; j < ans[i].appear; ++j)
			{
				if (i == 0 && j == 0)
				{
					cout << ans[i].val;
				}
				else
				{
					cout << " " << ans[i].val;
				}
			}
		}
		cout << endl;
	}
	return 0;
}