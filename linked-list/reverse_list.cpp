#include "single_linked_list_with_header"


void Print(List L);
ListNode* ReadList(ElementType a[N], ElementType len);
ListNode* ReverseList(List L);

ListNode* ReverseList(List L)
{
    ListNode* head = L;
    ListNode* tail = NULL;
    ListNode* l = NULL;
    while(head!=NULL)
    {
        l = head;
        head = head->next;
        l->next = tail;
        tail = l;
    }

    return tail;
}


ListNode* ReadList(int a[N], int len)
{
    ListNode* head = new ListNode(-1);
    ListNode* l = head;
    for(int i = 0; i < len; i++)
    {
        ListNode* p = new ListNode(a[i]);
        l->next = p;
        l = l->next;
    }
    l = head;
    head = l->next;
    l->next = NULL;
    delete l;
    return head;
}
