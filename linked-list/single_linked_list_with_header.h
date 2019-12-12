# ifndef _Single_Linked_List_H
# define _Single_Linked_List_H

// variable
struct Node;

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;

// function
// 1.print list
void Print(List l);

// 2.
List ReadList(ElementType a[N], ElementType len);
Position ReverseList(List l);

List MakeEmpty(List l);
int IsEmpty(List l);
int IsLast(Position p, List l);
Position Find(ElementType x, List l);
void Delete(ElementType x, List l);
Position FindPrevious(List l);
void Insert(ElementType x, List l, Position p);
void DeleteList(List l);
Position Header(List l);
Position First(List l);
Position Advance(Position p);
ElementType Retrieve(Position p);

# endif 
