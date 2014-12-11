#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int minim (int *dist, int *vis, int len)
{
    int i = 0, dclos = MAX;
    int clos = 0;
    for (i = 0; i < len; i++)
    {
        if ((vis[i] == 0) && (dist[i] < dclos))
        {
            clos = i;
            dclos = dist[i];
        }
    }
    return clos;
}
void display (int *dist, int *vis, int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d \t | \t %d \n", vis[i], dist[i]);
    }
}
void dijkstra (int **matrix, int len, int src)
{
    int i = 0, j = 0, v = 0;
    int *dist;
    int *vis;
    dist = (int*)malloc (sizeof(int)*len);
    vis = (int*)malloc (sizeof(int)*len);
    for (i = 0; i < len; i++)
    {
        dist[i] = MAX;
        vis[i] = 0;
    }
    dist[src] = 0;
    for (i = 0; i < len; i++)
    {
        v = minim (dist, vis, len);
        vis[v] = 1;
        for (j = 0; j < len; j++)
        {
            if((dist[j] > dist[v] + matrix[v][j]) && (matrix[v][j] != 0))
            {
                dist[j] = dist[v] + matrix[v][j];
            }
        }
    }
    display(dist, vis, len);

}
void floydw (int **matrix, int len)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        dijkstra (matrix, len, i);
        printf("\n");
    }
}
int main()
{
      /** READING FROM FILE AND INITIALIZING MATRIX*/

    FILE *f;
    f=fopen("matrix.txt","r");
    int n; int source;
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&source);
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
    dijkstra (a, n, source);
    printf("\n");
    floydw (a, n);
    return 0;
}
