#include <cstdio>
#include <cstdlib>


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* ReverseList(ListNode *L)
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


void Print(ListNode* L);
const int N = 5;
ListNode* ReadList(int a[N], int len);

int main()
{
    int a[N] = {1, 2, 3, 4, 5};
    int len = sizeof(a)/sizeof(int);
    ListNode* l = ReadList(a, len); 
    Print(l);
    l = ReverseList(l);
    Print(l);

    return 0;
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


void Print(ListNode* L)
{
    ListNode *head = L;
    if(L==NULL)
    {
        return ;
    }
    while(L !=NULL)
    {
        printf("%d,", L->val);
        L = L->next;
    }
    printf("\n");
}

