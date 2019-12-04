//
//
//描述
//
//Given a set of n jobs where each job i has a deadlineand profit associated to it.Each job takes 1 unit of time to complete and only one job can be scheduled at a time.We earn the profit ifand only if the job is completed by its deadline.The task is to find the maximum profitand the number of jobs done.
//
//输入
//
//The first line of input contains an integer T denoting the number of test cases.Each test case consist of an integer N denoting the number of jobsand the next line consist of Job id, Deadlineand the Profit associated to that Job.
//
//Constraints:1 <= T <= 100，1 <= N <= 100，1 <= Deadline <= 100，1 <= Profit <= 500
//
//	输出
//
//	Output the number of jobs done and the maximum profit.
//
//	输入样例 1
//
//	2
//	4
//	1 4 20 2 1 10 3 1 40 4 1 30
//	5
//	1 2 100 2 1 19 3 2 27 4 1 25 5 1 15
//
//	输出样例 1
//
//	2 60
//	2 127
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Job
{
	int benifit;
	int deadline;
	Job(int c = 0, int d = 0)
	{
		benifit = c;
		deadline = d;
	}
	bool operator < (Job a)
	{
		if (benifit == a.benifit)
		{
			deadline < a.deadline;
		}
		return benifit > a.benifit;
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
		vector<Job> jobs(n);
		for (int i = 0; i < n; ++i)
		{
			int id, deadline, benifit;
			cin >> id >> deadline >> benifit;
			jobs[i] = Job(benifit, deadline);
		}
		vector<bool> visit(n + 1, false);
		sort(jobs.begin(), jobs.end());
		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			int start = jobs[i].deadline < n ? jobs[i].deadline : n;
			for (int j = start - 1; j >= 0; j--)
			{
				if (!visit[j])
				{
					cnt++;
					visit[j] = true;
					sum += jobs[i].benifit;
					break;
				}
			}
		}
		cout << cnt << " " << sum << endl;
	}
	return 0;
}