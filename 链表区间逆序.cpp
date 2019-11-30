//
//
//����
//
//�����������ÿK���ڵ�֮�����򣬴�ӡ�������������K�Ľڵ�������Ҫ����Ҫ��ʱ�临�Ӷ�ΪO(n)������ռ临�Ӷ�ΪO(1)��
//
//����
//
//�����һ��Ϊ���������� ÿ���������������ÿһ�е�ֵ�ÿո��������һ����ʾ�����ȣ��м�Ϊ�ڵ�ֵ��������K��
//
//���
//
//�����ÿһ��Ϊ�µ������ڵ�ֵ�ÿո������ĩβ��Ҫ�ո�
//
//�������� 1
//
//2
//8 1 2 3 4 5 6 7 8 3
//8 a b c d e f g h 4
//
//������� 1
//
//3 2 1 6 5 4 7 8
//d c b a h g f e
//
#include <iostream>
using namespace std;
class LinkNode
{
public:
	string val;
	LinkNode* next;
	LinkNode(string v = "", LinkNode* n = NULL)
	{
		val = v;
		next = n;
	}
};
//�ҵ���ǰ��������һ���ڵ�
LinkNode* findTail(LinkNode* head, int num)
{
	int cnt = 0;
	while (head != NULL && cnt < num)
	{
		head = head->next;
		cnt++;
	}
	if (cnt < num)
	{
		return NULL;
	}
	return head;
}
void reverseK(LinkNode* head, int num, int k)
{
	LinkNode* curEnd;
	while ((curEnd = findTail(head, k)) != NULL)
	{
		//ת��ǰ�����һ���ڵ��ǰһ���ڵ�
		LinkNode* pre = head;
		//��head������һ������ĵ�һ���ڵ�
		head = head->next;
		//��һ������ĵ�һ���ڵ�
		LinkNode* tail = curEnd->next;

		LinkNode* traverse = head->next;
		LinkNode* revPre = head;
		while (traverse != tail)
		{
			LinkNode* next = traverse->next;
			traverse->next = revPre;
			revPre = traverse;
			traverse = next;
		}
		pre->next->next = tail;
		pre->next = curEnd;
	}
}
void printList(LinkNode* head)
{
	head = head->next;
	if (head != NULL)
	{
		cout << head->val;
		head = head->next;
	}
	while (head != NULL)
	{
		cout << " " << head->val;
		head = head->next;
	}
	cout << endl;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n;
		LinkNode* head = new LinkNode();
		LinkNode* tail = head;
		for (int i = 0; i < n; ++i)
		{
			string val;
			cin >> val;
			LinkNode* curNode = new LinkNode(val);
			tail->next = curNode;
			tail = tail->next;
		}
		cin >> k;
		reverseK(head, n, k);
		printList(head);
	}
	return 0;
}