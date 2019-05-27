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
-------��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
         �ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
		 ˼·��
		 ������һ��ͷ�ڵ㣨��ֹԭ�����һ�����־��ظ�����Ȼ���������ڵ���ɴ���ȥ����ɾѡ
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