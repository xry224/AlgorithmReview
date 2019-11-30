//
//
//描述
//
//判断一个单向链表是否为回文结构。自定义链表数据结构，要求时间复杂度为O(n)，额外空间复杂度为O(1)。
//
//输入
//
//输入第一行为用例个数， 每个测试用例输入的每一行的值用空格隔开，第一个值为节点个数，后面为每一个节点值
//
//输出
//
//是回文则输出true，不是则输出false，一行表示一个链表的结果。
//
//输入样例 1
//
//4
//3 1 2 1
//4 1 2 2 1
//3 3 5 3
//6 a b c d c a
//
//输出样例 1
//
//true
//true
//true
//false
//
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	Node* next = NULL;
	char val;
	Node(char var = ' ', Node* n = NULL)
	{
		next = n;
		val = var;
	}
};
void rever(Node* middle)
{
	Node* pre = middle;
	Node* cur = middle->next;
	while (cur != NULL)
	{
		Node* t = cur->next;
		cur->next = pre;
		pre = cur;
		cur = t;
	}
}
bool solve(Node* head, int num, Node* tail)
{
	int half = num / 2 + 1;
	Node* traverse = head;
	for (int i = 0; i < half; ++i)
	{
		traverse = traverse->next;
	}
	rever(traverse);
	int moveCnt = num / 2;
	head = head->next;
	for (int i = 0; i < moveCnt; ++i)
	{
		if (head->val != tail->val)
		{
			return false;
		}
		head = head->next;
		tail = tail->next;
	}
	return true;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		Node* head = new Node();
		Node* tra = head;
		for (int i = 0; i < n; ++i)
		{
			char value;
			cin >> value;
			Node* t = new Node(value);
			tra->next = t;
			tra = t;
		}
		if (solve(head, n, tra))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	return 0;
}