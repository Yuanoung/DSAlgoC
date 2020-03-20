#include <stdlib.h>
#include "list.h"



struct Node
{
    ElementType Element;
    Position Next;
};

List MakeEmpty( List L ) 
{
    DeleteList(L);
    return L;
}

/* Return true if empty */
int 
IsEmpty( List L ) 
{
    return L->Next == NULL;
}

/* Return true if P is the last position in list */
/* Parameter L is unused in this implementation */
int 
IsLast( Position P, List L ) 
{
    return P->Next == NULL;
}

/* Return Position of X in L; NULL if not found */
Position
Find( ElementType X, List L) 
{
    Position P;

    P = L->Next;
    while (P && P->Element != X)
        P = P->Next;

    return P;
}

/* Delete first occurrence of X from a list */
/* Assume use of a header node */
void
Delete( ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious( X, L );

    if ( !IsLast( P, L ) )  /* Assumption of header use! */
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free( TmpCell );
    }
}

/* If X is not found, then Next field of returned */
/* Position is NULL */
/* Assumes a header */
Position
FindPrevious( ElementType X, List L )
{
    Position P;

    P = L;
    while ( P->Next && P->Next->Element != X )
        P = P->Next;

    return P;
}

/* Insert (after legal position)
 *
 * Header implementation assumed
 * Parameter L is unused in this implementation
 */
void
Insert( ElementType X, List L, Position P)
{
    Position TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    // if ( TmpCell == NULL )
    //     FatalError( "Out of space!!!");

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;    
}

ElementType
Retrieve( Position P )
{
    return P->Element;
}

/* Delete List */
void
DeleteList( List L )
{
    Position P, Tmp;

    P = L->Next;
    L->Next =NULL;
    while ( P != NULL )
    {
        Tmp = P->Next;
        free( P );
        P = Tmp;
    }
}