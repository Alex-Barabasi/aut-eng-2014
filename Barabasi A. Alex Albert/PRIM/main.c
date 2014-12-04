#include <stdio.h>
#include <stdlib.h>

typedef struct nodeS
{
    int key;
    struct nodeS *prev, *next;
}NodeTS;
typedef struct nodeQ
{
    int key;
    struct nodeQ *prev, *next;
}NodeTQ;
NodeTS *rootS = NULL;
NodeTQ *rootQ = NULL;




void initQ ()
{
    rootQ = (NodeTQ*)malloc (sizeof(NodeTQ));
    rootQ -> prev = NULL;
    rootQ -> next = NULL;
}
void initS ()
{
    rootS = (NodeTS*)malloc (sizeof(NodeTS));
    rootS -> prev = NULL;
    rootS -> next = NULL;
}



void addQ (int value)
{
      NodeTQ *p, *q;
      if (rootQ == NULL)
      {
          initQ ();
          rootQ -> key = value;
      }
      else
      {
          p = rootQ;
          while (p->next != NULL) p = p->next;
          q = (NodeTQ*)malloc (sizeof(NodeTQ));
          p -> next = q;
          q -> key = value;
          q -> next = NULL;
          q -> prev = p;
      }
}
void popQ (int *value)
{
    if (rootQ == NULL) return;
    else
    {
        (*value) = rootQ -> key;
        //printf("%d\n", (*value));
        if ((rootQ -> next) != NULL)
        {
            rootQ =  rootQ -> next;
            rootQ -> prev = NULL;
        }
    }
}



void addS (int value)
{
      NodeTS *p;
      if (rootS == NULL)
      {
          initS ();
          rootS -> key = value;
      }
      else
      {
          p = (NodeTS*)malloc (sizeof(NodeTS));
          p -> key = value;
          p -> prev = rootS;
          p -> next = NULL;
          rootS = p;
      }
}
void popS (int *value)
{
    if (rootS == NULL) printf("is NULL");
    else
    {
        (*value) = rootS -> key;
        //printf("%d\n", (*value));
        if ((rootS -> prev) != NULL)
        {
            rootS =  rootS -> prev;
            rootS -> next = NULL;
        }
        else
        {
            free(rootS);
            rootS = NULL;
        }
    }
}

void printpath (int *vect, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%c\n", (vect[i]+65));
    }
}
void prim (int **matrix, int len)
{
    int i = 0; int minim = 10000;
    int k1, k2, sz = 1, csz = 0;
    int insub[len];
    char ok1 = 0, ok2 = 0;
    insub[sz-1] = i;
  while (1)
  {
    for ( i = 0; i < (sz*len); i++)
    {
        ok1 = 0;
        ok2 = 0;
        for (csz = 0; csz < sz; csz++)
        {
            if (insub[csz] == i%len) ok1 = 1;
        }
        for (csz = 0; csz < sz; csz++)
        {
            if (insub[csz] == i/len) ok2 = 1;
        }
        if ((ok1 != 1) || (ok2 != 1))
        {
            if ((matrix[i%len][i/len] < minim) && (matrix[i%len][i/len] != 0))
            {
                k1 = i % len;
                k2 = i / len;
                minim = matrix[i%len][i/len];
            }
        }
    }

    for (csz = 0; csz < sz; csz++)
    {
        if (insub[csz] == k2)
        {
            insub[sz] = k1;
            sz++;
        }
    }
    minim = 10000;
    if (sz == len)
    {
        printpath(insub, len);
        return;
    }
  }
}

int main()
{
    /** READING FROM FILE AND INITIALIZING MATRIX*/

    FILE *f;
    f=fopen("matrix.txt","r");
    int n;
    fscanf(f,"%d",&n);

    int i,j;
    int **a=(int**)malloc(n*sizeof(int*));
    for (i=0;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
    }

    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            fscanf(f,"%d",&a[i][j]);
    fclose(f);

    printf("\nThe matrix is:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            printf("%-3d",a[i][j]);
        printf("\n");
    }
    prim (a, n);
    return 0;
}
