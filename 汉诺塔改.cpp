/*


����

��ŵ�����������Ʋ��ܽ�һ����ֱ�Ӵ�������ƶ������Ҳ࣬Ҳ����ֱ�Ӵ����Ҳ��ƶ�������࣬���Ǳ��뾭���м䡣����N������ʱ���ƶ�������

����

�����һ��Ϊ���������� ÿ��������������ĵ�һ��ΪN��

���

�ƶ�������

�������� 1

1
2

������� 1

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
	//����n-1����a��b�ٵ�c
	Hannuo(layer - 1, a, b, c, ans);
	//a->b
	ans++;
	//����n-1����c��b�ٵ�a
	Hannuo(layer - 1, c, b, a, ans);
	//b->c
	ans++;
	//����n-1����c��b�ٵ�a
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