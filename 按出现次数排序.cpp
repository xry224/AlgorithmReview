//
//
//����
//
//�Ը��������е�Ԫ�ذ���Ԫ�س��ֵĴ������򣬳��ִ����������ǰ�棬������ִ�����ͬ��������ֵ��С�������磬��������Ϊ{ 2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12 }�����������Ϊ{ 3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5 }��
//
//����
//
//����ĵ�һ��Ϊ��������������ÿһ������ʹ�����б�ʾ����һ��Ϊ���鳤�ȣ��ڶ���Ϊ�������ݣ�����Ԫ�ؼ�ʹ�ÿո������
//
//���
//
//ÿһ����������������һ���������Ԫ��֮��ʹ�ÿո������
//
//�������� 1
//
//1
//4
//2 3 2 5
//
//������� 1
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