/*


����

Cows in the FooLand city are interesting animals. One of their specialties is related to producing offsprings. A cow in FooLand produces its first calve (female calf) at the age of two years and proceeds to produce other calves (one female calf a year).

Now the farmer Harold wants to know how many animals would he have at the end of N years, if we assume that none of the calves die, given that initially, he has only one female calf?

explanation:At the end of 1 year, he will have only 1 cow, at the end of 2 years he will have 2 animals (one parent cow C1 and other baby calf B1 which is the offspring of cow C1).At the end of 3 years, he will have 3 animals (one parent cow C1 and 2 female calves B1 and B2, C1 is the parent of B1 and B2).At the end of 4 years, he will have 5 animals (one parent cow C1, 3 offsprings of C1 i.e. B1, B2, B3 and one offspring of B1).

����

The first line contains a single integer T denoting the number of test cases. Each line of the test case contains a single integer N as described in the problem.

���

For each test case print in new line the number of animals expected at the end of N years modulo 10^9 + 7.

�������� 1

2
2
4

������� 1

2
5


*/
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define MOD 1000000007
//����n=2ʱfibΪ2��Ϊ1�������ʵ��ȡֵΪ쳲��������е�n+1��
//�������Ϊ��
//��nΪż������An=(An/2)^2 + (A(n/2-1))^2
//����An=An/2 * (An/2 + 2 * A(n/2-1))
//쳲���������ʵ�ʹ��ɵ���ż�������������෴
long long cal(map<long long, long long>& cow, long long n)
{
	if (cow[n] != 0)
	{
		return cow[n];
	}
	if (n % 2 == 0)
	{
		cow[n] = (cal(cow, n / 2) * cal(cow, n / 2) + cal(cow, n / 2 - 1) * cal(cow, n / 2 - 1)) % MOD;
	}
	else
	{
		cow[n] = (cal(cow, n / 2) * (cal(cow, n / 2) + 2 * cal(cow, n / 2 - 1))) % MOD;
	}
	return cow[n];
}
int main()
{
	int T;
	cin >> T;
	map<long long, long long> cow;
	cow[0] = 1;
	cow[1] = 1;
	cow[2] = 2;
	cow[3] = 3;
	cow[4] = 5;
	while (T--)
	{
		long long n;
		cin >> n;
		cout << cal(cow, n) << endl;
	}
	return 0;
}