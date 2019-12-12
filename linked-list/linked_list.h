# ifndef _List_H
# define _List_H
struct Node;

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

//
List MakeEmpty(List L);
// O(1)
int IsEmpty(List L);
// O(1)
int IsLast(Position P, List L);
// O(N)
Position Find(ElementType X, List L);
// O(N)
void Delete(ElementType X, List L);
// O(N)
Position FindPrevious(ElementType X, List L);
// O(1)
void Insert(ElementType X, List L, Position P);
//O(N)
void DeleteList(List L);
//O(
Position Header(List L);
//O(
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

# endif 
