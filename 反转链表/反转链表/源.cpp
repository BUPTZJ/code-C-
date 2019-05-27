#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

ListNode * ReverseList(ListNode* phead)
{
	if (phead == nullptr)
		return nullptr;
	ListNode* pre = nullptr;
	ListNode* cur = phead;
	ListNode* reversehead = nullptr;
	while (cur)
	{
		if (cur->next == nullptr)
		{
			reversehead = cur;
		}
		ListNode* next = cur->next;
		cur->next = pre; //ָ�뷴ת
		pre = cur;
		cur = next;
	}
	return  reversehead;
}
int main()
{
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	a1.next = &a2;
	a2.next = &a3;
	ListNode *reverseHead = ReverseList(&a1);
	ListNode* cur = reverseHead;
	while (cur)
	{
		cout << cur->val<<" ";
		cur = cur->next;
	}
	system("pause");
	return 0;

}