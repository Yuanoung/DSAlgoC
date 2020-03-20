#include <stdio.h>
#include "list.c"

#define ElementType int

void PrintList( List L )
{
    Position P;

    P = L->Next;
    while ( P ) {
        printf("%d\n", P->Element);
        P = P->Next;
    }
}

int main(int argc, char const *argv[])
{
    Position DummyNode = malloc( sizeof( struct Node ));
    // if ( DummyNode == NULL )
    //     FatalError( "Out of space!!!" );

    Insert(1, DummyNode, DummyNode);
    PrintList( DummyNode );
    return 0;
}
