#include "double_linked_list"


struct Node
{
    ElementType element;
    Position next;
    Position prev;
};

int IsEmpty(List l)
{
    return l->Next == NULL;
}

int IsLast(Position p, List l)
{
    return p->Next == NULL;
}

void Insert(ElementType x, List l, Position p)
{
    Position new_node;
    new_node = malloc(sizeof(struct Node))

    if(new_node == NULL)
        printf("%s", "can't malloc memory!")

    new_node->element = x;
    new_node->next = p->next;
    p->next = new_node;
    new_node->prev = p;
    new_node->next->prev = new_node;
    
}

Position FindPrevious(ElementType x, List l)
{
    Position p;
    p = l;
    while(p->next != NULL && p->next->element != x)
    {
        p = p->next;
    }
    return p;
}

void Delete(ElementType x, List l)
{
    Position p, tmp;
    p = FindPrevious(x, l);
    tmp = p->next;  // x in tmp
    p->next = tmp->next;    //p->next
    tmp->next->prev = tmp->prev;    // previous
    free(tmp);
}

void DeleteList(List l)
{
    Position p, tmp;
    p = l->next;
    while(p!=NULL)
    {
        tmp = p->next;
        free(p);
        p = tmp->next;
    }

}
