#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int value;
    struct nodetype *next;
} NodeT;
NodeT *first, *last;
void init()
{
    first = NULL; last = NULL;
    first = (NodeT*)malloc ( sizeof( NodeT));
    last = (NodeT*)malloc ( sizeof( NodeT));
    first->next = last;
    first->value =  20;
    last->value = 30;
}
void addlast (int nv)
{
    NodeT *NEW;
    NEW =(NodeT*)malloc ( sizeof( NodeT));
    NEW->value = nv;
    NEW->next = NULL;
    last->next = NEW;
    last = NEW;
}
void print()
{
    NodeT *WRITE;
    WRITE = first;
    while ( WRITE != NULL )
    {
        printf("%d ", WRITE->value);
        WRITE = WRITE->next;
    }
}
void addfirst (int nv)
{
    NodeT *NEW;
    NEW =(NodeT*)malloc ( sizeof( NodeT));
    NEW->value = nv;
    NEW->next = first;
    first = NEW;
}
int main()
{
    init();
    addlast(50);
    addfirst(5);
    print();
}
