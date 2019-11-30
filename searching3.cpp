/*


描述

They declared Sonam as bewafa. Although she is not, believe me! She asked a number of queries to people regrading their position in a test. Now its your duty to remove her bewafa tag by answering simple queries. All the students who give test can score from 1 to 10^18. Lower the marks, better the rank. Now instead of directly telling the marks of student they have been assigned groups where marks are distributed in continuous intervals, you have been given l(i) lowest mark of interval i and r(i) highest marks in interval i. So marks distribution in that interval is given as l(i), l(i)+1, l(i)+2 . . . r(i)

Now Sonam ask queries in which she gives rank of the student (x) and you have to tell marks obtained by that student

Note: rank1 is better than rank2 and rank2 is better than rank3 and so on and the first interval starts from 1.

Constraints:1<=T<=50,1<=N<=10^5,1<=Q<=10^5,1<= l(i) < r(i) <=10^18,1<=x<=10^18

输入

The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. Each test case contains two space separated values N and Q denoting the no of groups and number of queries asked respectively. The next line contains N group of two integers separated by space which shows lowest marks in group i ie l(i) and highest marks in group i ie r(i) such that if i < j then r(i) < l(j). The next lines contain Q space separated integers x, denoting rank of student.

输出

For each query output marks obtain by student whose rank is x(1<=x<=10^18).

输入样例 1

1
3 3
1 10 12 20 22 30
5 15 25

输出样例 1

5 16 27


*/
//两个问题：
//1. 测试用例输出最后一项后面仍然会跟空格
//2. 测试用例查询的rank会在所给范围之外
//比如给范围 1 4 6 8，即使1 2 3 4 6 7 8，查询可能会查10，结果应该为11
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void process(vector<pair<long long, long long>>& group, vector<long long>& difference)
{
	for (int i = 0; i < group.size(); ++i)
	{
		//求每组能表示的rank的数量
		difference[i] = group[i].second - group[i].first + 1;
	}
}
long long search(vector<pair<long long, long long>>& group, long long target, vector<long long>& difference)
{
	long long temp = target;
	//long long disSum = 0;
	for (int i = 0; i < group.size(); ++i)
	{
		if (temp <= difference[i])
		{
			return group[i].first + temp - 1;
		}
		else
		{
			temp -= difference[i];
			//测试用例查询的rank会在所给范围之外
			if (i == group.size() - 1)
			{
				return group[i].second + temp;
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long n, q;
		cin >> n >> q;
		vector<pair<long long, long long>> group(n);
		for (long long i = 0; i < n; ++i)
		{
			long long l, h;
			cin >> l >> h;
			group[i] = make_pair(l, h);
		}
		long long query;
		vector<long long> ans(q);
		vector<long long> difference(n);
		process(group, difference);
		for (long long i = 0; i < q; ++i)
		{
			cin >> query;
			ans[i] = search(group, query, difference);
		}
		for (long long i = 0; i < ans.size(); ++i)
		{
			if(i == 0)
			{
				cout <<ans[i];
			}
			else
			{
				cout <<" "<<ans[i];
			}
		}
		cout << endl;
	}
	return 0;
}