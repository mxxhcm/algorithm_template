#include "linked_list.h"


struct Node{
    ElementType element;
    Position next;
}

void Print(List l)
{
    if(l==NULL)
        return;
    Position p;
    p = l->next;
    while(p!=NULL)
    {
        printf("%d\n", p->element);
        p = p->next;
    }
}

Position ReverseList(List l)
{
    Position p;
    p = l->next;
    tmp = l->next;

    p->next = NULL;
    while(tmp!=NULL)
    {
        tmp->next = p;
        p = tmp; 
        tmp = tmp->next;
    }
    l->next = p;

    return l;
}

// O(1)
int IsEmpty(List l)
{
    return l->next == NULL;
}

// O(1)
int IsLast(Position p, List l)
{
    return p->next == NULL;
}

// O(N)
Position Find(ElementType x, List l)
{
    Position p;
    p = l->next;
    while(p!=NULL && p->Element != x)
    {
        p = p->next;
    }
    return p;
}

// O(N)
Position FindPrevious(ElementType X, List l)
{
    Position p;
    p = l;
    while(p->next !=NULL && p->next->element != x)
    {
        p = p->next;
    }

    return p;
}

// O(N)
void Delete(ElementType x, List l)
{
    Position p, tmp;
    p = FindPrevious(x, l); 
    if(!IsLast(p))
    {
        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }
}

// O(1)
Void Insert(ElementType x, List l, Position p)
{
    Position tmp;
    tmp = malloc(sizeof(struct Node));
    if(tmp == NULL)
    {
        FatalError("Out of space");
    }
    tmp->element = x;
    tmp->next = p->next;
    n->next = tmp;
}

void DeleteList(List l)
{
    Position p, tmp;
    p = l->next;
    l->next = NULL;
    while(p!=NULL)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}

Position First(List l)
{
    Position p;

    p = l->next;
    return p;
}

Position Head(List l)
{
    Position p;
    p = L;
    return p;    
}

Position Advance(Position p)
{
    return p;
}

