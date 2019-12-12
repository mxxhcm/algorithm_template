#include <cstdio>
#include <cstdlib>


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

const int N = 4;

ListNode* Merge(ListNode *l1, ListNode *l2);
ListNode* ReadList(int a[N], int len);
void Print(ListNode* L);


int main()
{
    int a1[N] = {1, 2, 3, 4};
    int a2[N] = {1, 2, 3, 4};
    int len1 = sizeof(a1)/sizeof(int);
    int len2 = sizeof(a2)/sizeof(int);
    ListNode* l1 = ReadList(a1, len1); 
    Print(l1);

    ListNode* l2 = ReadList(a2, len1);
    Print(l2);

    ListNode* l = Merge(l1, l2);
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

ListNode* Merge(ListNode *l1, ListNode *l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    ListNode *head = new ListNode(-1);
    ListNode *l = head;
    
    while((l1 !=NULL) && (l2 != NULL))
    {
        if(l1->val <= l2->val)
        {
            l->next = l1;
            l1 = l1->next;
        }
        else
        {
            l->next = l2;
            l2 = l2->next;
        }
        l = l->next;
    }
    if(l1 !=NULL)
    {
        l->next = l1;
    }
    if(l2 !=NULL)
    {
        l->next = l2;
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


