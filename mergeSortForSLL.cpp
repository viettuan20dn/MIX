#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};

ListNode *getMid(ListNode *head)
{
    ListNode *midPrev = nullptr;
    while (head && head->next)
    {
        midPrev = (midPrev == nullptr) ? head : midPrev->next;
        head = head->next->next;
    }
    ListNode *mid = midPrev->next;
    midPrev->next = nullptr;
    return mid;
}
// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    ListNode dummyHead(0);
    ListNode *ptr = &dummyHead;
    while (a && b)
    {
        if (a->val < b->val)
        {
            ptr->next = a;
            a = a->next;
        }
        else
        {
            ptr->next = b;
            b = b->next;
        }
        ptr = ptr->next;
    }
    if (a)
        ptr->next = a;
    else
        ptr->next = b;

    return dummyHead.next;
}

// Sort and unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head) {
    if (!head || !head->next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* left = mergeSortList(head);
        ListNode* right = mergeSortList(mid);
        return mergeLists(left, right);
}

int main()
{
	int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8};
	ListNode* a=new ListNode(1);
	a->next=new ListNode(3);
	a->next->next=new ListNode(5);
	a->next->next->next= new ListNode(7);
	a->next->next->next->next= new ListNode(9);

	ListNode* b=new ListNode(2);
	b->next=new ListNode(4);
	b->next->next=new ListNode(6);
	b->next->next->next= new ListNode(8);

    //ListNode* merged = mergeLists(a, b);

}