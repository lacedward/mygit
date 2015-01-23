#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define VERTEXNUM 5

typedef struct edge
{
    int vertex;
    struct edge* next;
}vertexNd, edgeNd;

typedef enum{FALSE,TRUE}Boolean;

void CreateGraph(vertexNd **Vnode, int start, int end)
{
    vertexNd *Enode = (edgeNd*)malloc(sizeof(edgeNd)*VERTEXNUM);
    Enode->next = NULL;
    Enode->vertex = end;
    Vnode = Vnode + start;
    while((*Vnode)->next != NULL)
    {
        *Vnode = (*Vnode)->next;
    }
    (*Vnode)->next = Enode;
}

void DisplayGraph(vertexNd **Vnode)
{
    int i;
    vertexNd *p;
    for(i=0; i<VERTEXNUM; i++)
    {
        printf("%d->", i);
        p = *(Vnode + i);

        while(p->next != NULL)
        {
            p = p->next;
            printf("%d->",p->vertex);
        }
        printf("/n");
    }
}

void DFT(vertexNd **Vnode, int visited[VERTEXNUM])
{
    int i;
    for(i=0; i<VERTEXNUM; i++)
    {
        DFTcore(Vnode, i, visited[VERTEXNUM]);
    }
}

void DFTcore(vertexNd **Vnode, int i, int visited[VERTEXNUM])
{
    vertexNd *p;
    if(visited[i] == 1)
    {
        return;
    }
    visited[i] = 1;
    printf("%d->", i);
    Vnode = Vnode + i;
    p = *Vnode;
    while (p->next != NULL)
    {
        DFTcore(Vnode, p->vertex, visited[VERTEXNUM]);
        p = p->next;

    }
}


int main()
{
    int i;
    vertexNd **Vnode = (vertexNd**)malloc(sizeof(vertexNd*)*VERTEXNUM);
    int visited[VERTEXNUM];

    for(i=0; i<VERTEXNUM; i++)
    {
        Vnode = Vnode + i;
        (*Vnode)->vertex = i;
        (*Vnode)->next = NULL;
    }
    for(i=0; i<VERTEXNUM; i++)
    {
        visited[i] = 0;
    }

//初始化结束，开始创建图
    CreateGraph(Vnode, 0, 3);
    CreateGraph(Vnode, 0, 4);
    CreateGraph(Vnode, 3, 1);
    CreateGraph(Vnode, 3, 2);
    CreateGraph(Vnode, 4, 1);

    DisplayGraph(Vnode);

//DFT
    DFT(Vnode, visited[VERTEXNUM]);


    return 0;
}
