/*
–Ú∫≈≥À∑Ω

√Ë ˆ

There are Infinite People Standing in a row, indexed from 1.A person having index 'i' has strength of (i*i).You have Strength 'P'. You need to tell what is the maximum number of People You can Kill With your Strength P.You can only Kill a person with strength 'X' if P >= 'X' and after killing him, Your Strength decreases by 'X'.

 ‰»Î

First line contains an integer 'T' - the number of testcases,Each of the next 'T' lines contains an integer 'P'- Your Power.Constraints:1<=T<=100001<=P<=1000000000000000

 ‰≥ˆ

For each testcase Output The maximum Number of People You can kill.

 ‰»Î—˘¿˝ 1

1
14

 ‰≥ˆ—˘¿˝ 1

3


*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long n;
		cin >> n;
		long long ans = 0;
		for (long long i = 1;; ++i)
		{
			long long power = i * i;
			if (n < power)
			{
				break;
			}
			ans++;
			n -= power;
		}
		cout << ans << endl;
	}
	return 0;
}