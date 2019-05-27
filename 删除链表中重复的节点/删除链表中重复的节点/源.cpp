#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(nullptr){}
};
/*
-------在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
         重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
		 思路：
		 新增加一个头节点（防止原链表第一个数字就重复），然后定义两个节点组成窗口去遍历删选
*/
class Solution
{
public:
	ListNode * deleteDuplication(ListNode* phead)
	{
		if (phead == nullptr || phead->next == nullptr)
			return phead;

		ListNode* head = new ListNode(0);
		head->next = phead;
		ListNode* p = head;
		ListNode* q = phead;
		while (q)
		{
			while (q->next && (q->val == q->next->val))
			{
				q = q->next;
			}
			if (p->next != q)
			{
				q = q->next;
				p->next = q;
				
			}
			else
			{
				p = q;
				q = q->next;
			}
		}
		return head->next;
	}

};
int main()
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(3);
	ListNode e(4);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	Solution s;
	ListNode* head=s.deleteDuplication(&a);
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
	system("pause");
	return 0;

}