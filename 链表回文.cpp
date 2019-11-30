//
//
//����
//
//�ж�һ�����������Ƿ�Ϊ���Ľṹ���Զ����������ݽṹ��Ҫ��ʱ�临�Ӷ�ΪO(n)������ռ临�Ӷ�ΪO(1)��
//
//����
//
//�����һ��Ϊ���������� ÿ���������������ÿһ�е�ֵ�ÿո��������һ��ֵΪ�ڵ����������Ϊÿһ���ڵ�ֵ
//
//���
//
//�ǻ��������true�����������false��һ�б�ʾһ������Ľ����
//
//�������� 1
//
//4
//3 1 2 1
//4 1 2 2 1
//3 3 5 3
//6 a b c d c a
//
//������� 1
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