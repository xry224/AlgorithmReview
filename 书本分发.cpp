/*


描述

You are given N number of books. Every ith book has Pi number of pages. You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations, and print this minimum value. Each book will be allocated to exactly one student. Each student has to be allocated atleast one book.

输入

The first line contains 'T' denoting the number of testcases. Then follows description of T testcases:Each case begins with a single positive integer N denoting the number of books.The second line contains N space separated positive integers denoting the pages of each book.And the third line contains another integer M, denoting the number of studentsConstraints:1<= T <=70，1<= N <=50，1<= A [ i ] <=250，1<= M <=50，Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see explanation for better understanding)

输出

For each test case, output a single line containing minimum number of pages each student has to read for corresponding test case.

输入样例 1

1
4
12 34 67 90
2

输出样例 1

113


*/
#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int>& arr, int num, int maxBook, long long sum)
{
	int left = maxBook;
	long long right = sum;
	long long minRead = 0;
	while (left <= right)
	{
		int cost = 0;
		minRead = (left + right) / 2;
		int read = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			if (arr[i] > minRead)
			{
				cost = num;
				break;
			}
			if (read + arr[i] <= minRead)
			{
				read += arr[i];
			}
			else
			{
				read = arr[i];
				cost++;
			}
		}
		cost++;
		if (cost <= num)
		{
			right = minRead - 1;
		}
		else
		{
			left = minRead + 1;
		}
	}
	cout << left  << endl;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		long long sum = 0;
		int maxBook = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			sum += arr[i];
			maxBook = arr[i] > maxBook ? arr[i] : maxBook;
		}
		int numberOfStudents;
		cin >> numberOfStudents;
		if (numberOfStudents > n)
		{
			cout << -1 << endl;
			continue;
		}
		solve(arr, numberOfStudents, maxBook, sum);
	}
	return 0;
}