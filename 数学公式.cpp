/*


描述

Implement pow(A, B) % C.In other words, given A, B and C, find (A^B)%C

输入

The first line of input consists number of the test cases. The following T lines consist of 3 numbers each separated by a space and in the following order:A B C'A' being the base number, 'B' the exponent (power to the base number) and 'C' the modular.Constraints:1 ≤ T ≤ 70,1 ≤ A ≤ 10^5,1 ≤ B ≤ 10^5,1 ≤ C ≤ 10^5

输出

In each separate line print the modular exponent of the given numbers in the test case.

输入样例 1

3
3 2 4
10 9 6
450 768 517

输出样例 1

1
4
34
*/
#include <iostream>
#include <vector>
using namespace std;
int solve(int base, int exp, int modular)
{
	long long baseAns = base;
	long long ans = 1;
	int n = exp;
	while (n > 0)
	{
		if (n % 2 == 0)
		{
			n /= 2;
			baseAns = baseAns * baseAns % modular;
		}
		else
		{
			ans = ans * baseAns % modular;
			n--;
		}
	}
	return ans;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int base, exp, modular;
		cin >> base >> exp >> modular;
		cout << solve(base, exp, modular) << endl;
	}
	return 0;
}
