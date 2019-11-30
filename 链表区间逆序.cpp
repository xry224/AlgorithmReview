//
//
//描述
//
//将单个链表的每K个节点之间逆序，打印出新链表；最后不足K的节点数不需要逆序；要求时间复杂度为O(n)，额外空间复杂度为O(1)。
//
//输入
//
//输入第一行为用例个数， 每个测试用例输入的每一行的值用空格隔开，第一个表示链表长度，中间为节点值，最后代表K。
//
//输出
//
//输出的每一行为新的链表，节点值用空格隔开，末尾不要空格。
//
//输入样例 1
//
//2
//8 1 2 3 4 5 6 7 8 3
//8 a b c d e f g h 4
//
//输出样例 1
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
//找到当前区间的最后一个节点
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
		//转换前区间第一个节点的前一个节点
		LinkNode* pre = head;
		//将head移至下一个区间的第一个节点
		head = head->next;
		//下一个区间的第一个节点
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