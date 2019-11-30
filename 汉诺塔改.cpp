/*


描述

汉诺塔问题中限制不能将一层塔直接从最左侧移动到最右侧，也不能直接从最右侧移动到最左侧，而是必须经过中间。求当有N层塔的时候移动步数。

输入

输入第一行为用例个数， 每个测试用例输入的第一行为N。

输出

移动步数。

输入样例 1

1
2

输出样例 1

8
*/
#include <iostream>
#include <algorithm>
using namespace std;
void Hannuo(int layer, char a, char b, char c, int& ans)
{
	if (layer == 1)
	{
		ans += 2;
		return;
	}
	//顶上n-1个从a到b再到c
	Hannuo(layer - 1, a, b, c, ans);
	//a->b
	ans++;
	//顶上n-1个从c到b再到a
	Hannuo(layer - 1, c, b, a, ans);
	//b->c
	ans++;
	//顶上n-1个从c到b再到a
	Hannuo(layer - 1, a, b, c, ans);
}
int Hanoi(int n)
{
	if (n == 1)
	{
		return 2;
	}
	return Hanoi(n - 1) * 3 + 2;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int ans = 0;
		Hannuo(n, 'a', 'b', 'c', ans);
		cout << ans << endl;
	}
	return 0;
}