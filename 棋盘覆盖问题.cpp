/*

����

���̸������⣺����һ����СΪ2^ n2^ n��С��������̣�������һ��λ���Ѿ�����䣬����Ҫ��һ��L��
��22��С������ɵĴ󷽸���ȥ������һ��С������״ȥ����ʣ�µ�С����������Ƿ�����
����Щ�����µ�С����ʹ��ͬһ��L�͸��Ӹ��ǡ�ע�⣺�����0��ʼ�����Ϸ��ĵ�һ����������Ϊ(0, 0)��
��һ�еڶ�������Ϊ(0, 1)���ڶ��е�һ��Ϊ(1, 0)���Դ����ơ�

����

�����һ��Ϊ������������������ÿһ�����������У���һ��Ϊnֵ������ĸ��ӵ����꣨�ÿո��������
�ڶ���Ϊ��Ҫ����������ͬһ��L�͸��ӵĸ������ꡣ

���

���ÿһ��Ϊһ�������Ľ⣬�Ȱ�����ֵ��С�����ٰ�����ֵ��С�����˳�����ÿһ���������������ꣻ
�ö��Ÿ�����

�������� 1

1
1 1 1
0 0

������� 1

0 1, 1 0

*/

#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
struct point
{
	int x = 0;
	int y = 0;
	point(int a, int b)
	{
		x = a;
		y = b;
	}
	bool operator < (const point& a)const
	{
		if (this->x == a.x)
		{
			return this->y < a.y;
		}
		return this->x < a.x;
	}
};
void fillBoard(point topLeft, vector<vector<int>>& board, point special, int length)
{
	if (length == 1)
	{
		return;
	}
	static int index = 1;
	int curIndex = index++;
	int nextSize = length / 2;
	//�����λ�����ϲ���������
	if (special.x < topLeft.x + nextSize && special.y < topLeft.y + nextSize)
	{
		fillBoard(topLeft, board, special, nextSize);
	}
	//�����½Ǽ��������
	else
	{
		point nextSp(topLeft.x + nextSize - 1, topLeft.y + nextSize - 1);
		board[nextSp.x][nextSp.y] = curIndex;
		fillBoard(topLeft, board, nextSp, nextSize);
	}
	//����ʣ������
	//���Ͻ�
	point tleft(topLeft.x, topLeft.y + nextSize);
	if (special.x >= tleft.x && special.y >= tleft.y && special.x < tleft.x + nextSize && special.y < tleft.y + nextSize)
	{
		fillBoard(tleft, board, special, nextSize);
	}
	else
	{
		point nextsp(tleft.x + nextSize - 1, tleft.y);
		board[nextsp.x][nextsp.y] = curIndex;
		fillBoard(tleft, board, nextsp, nextSize);
	}
	tleft = point(topLeft.x + nextSize, topLeft.y);
	//cout << tleft.x << " " << tleft.y << " " << nextSize << endl;
	if (special.x >= tleft.x && special.y >= tleft.y && special.x < tleft.x + nextSize && special.y < tleft.y + nextSize)
	{
		fillBoard(tleft, board, special, nextSize);
	}
	else
	{
		point nextsp(tleft.x, tleft.y + nextSize - 1);
		board[nextsp.x][nextsp.y] = curIndex;
		fillBoard(tleft, board, nextsp, nextSize);
	}
	tleft = point(topLeft.x + nextSize, topLeft.y + nextSize);
	if (special.x >= tleft.x && special.y >= tleft.y && special.x < tleft.x + nextSize && special.y < tleft.y + nextSize)
	{
		fillBoard(tleft, board, special, nextSize);
	}
	else
	{
		point nextsp(tleft.x, tleft.y);
		board[nextsp.x][nextsp.y] = curIndex;
		fillBoard(tleft, board, nextsp, nextSize);
	}
	
}
void getAns(vector<vector<int>>& board, int tX, int tY, vector<point>& ans)
{
	int target = board[tX][tY];
	int size = board.size();
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			int nextX = tX + i;
			int nextY = tY + j;
			if (nextX >= 0 && nextX < size && nextY >= 0 && nextY < size)
			{
				if (board[nextX][nextY] == target)
				{
					ans.emplace_back(point(nextX, nextY));
				}
			}
		}
	}
}
void printBoard(vector<vector<int>> board)
{
	//cout << "!" << endl;
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, specialX, specialY;
		int targetX, targetY;
		cin >> n >> specialX >> specialY;
		cin >> targetX >> targetY;
		int size = pow(2, n);
		vector<vector<int>> board(size, vector<int>(size));
		point special(specialX, specialY);
		point topLeft(0, 0);
		fillBoard(topLeft, board, special, size);
		//printBoard(board);
		vector<point> ans;
		getAns(board, targetX, targetY, ans);
		sort(ans.begin(), ans.end());
		cout << ans[0].x << " " << ans[0].y << "," << ans[1].x << " " << ans[1].y << endl;

	}
	return 0;
}