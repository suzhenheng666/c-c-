#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#define NUM 20
typedef struct
{
    char data[NUM];
    int edge[NUM][NUM];
    int vexnum, arcnum;
}Graph;

void initGraph(Graph* g,char* vertexLabels,int vertexNum,int edgeNum)
{
    for(int i=0;i<vertexNum;i++)
    {
        for(int j=0;j<vertexNum;j++)
        {
            g->edge[i][j]=__INT_MAX__;
        }
    }
    for (int i = 0; i < vertexNum; i++)
    {
        g->data[i] = vertexLabels[i];
    }
    g->vexnum = vertexNum;
    g->arcnum = edgeNum;
}

int getindex(Graph* g,char vertex)
{
    for(int i=0;i<g->vexnum;i++)
    {
        if(g->data[i]==vertex)
        {
            return i;
        }
    }
    return -1;
}

void addedge(Graph* g,char vertex1,char vertex2,int weight)
{
    int pos1=-1,pos2=-1;
    pos1=getindex(g,vertex1);
    pos2=getindex(g,vertex2);
    assert(pos1!=-1&&pos2!=-1);
    g->edge[pos1][pos2]=weight;
    g->edge[pos2][pos1]=weight;
}

void PrintGraph(Graph* g)
{
    printf("     ");
    for(int i=0;i<g->vexnum;i++)
    {
        printf("%-5c",g->data[i]);
    }
    printf("\n");
    for(int i=0;i<g->vexnum;i++)
    {
        printf("%-5c",g->data[i]);
        for(int j=0;j<g->vexnum;j++)
        {
            if(g->edge[i][j]==__INT_MAX__)
            {
                printf("%-5s","MAX");
            }
            else
            {
                printf("%-5d",g->edge[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void _DFS(Graph* g,int v,bool* visited)
{
    visited[v]=true;
    printf("%c ",g->data[v]);
    for(int i=0;i<g->vexnum;i++)
    {
        if(g->edge[v][i]!=__INT_MAX__&&!visited[i])
        {
            _DFS(g,i,visited);
        }
    }
}

void DFS(Graph* g)
{
    bool* visited=malloc(sizeof(bool)*g->vexnum);
    for(int i=0;i<g->vexnum;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<g->vexnum;i++)
    {
        if(!visited[i])
        {
            _DFS(g,i,visited);
        }
    }
    free(visited);
}
 
void _BFS(Graph* g,int v,bool* visited)
{
    visited[v]=true;
    Queue q;
    initQueue(&q);
    queuePush(&q,v);
    while(!queueIsEmpty(&q))
    {
        int front=queuePop(&q);
        printf("%c ",g->data[front]);
        for(int i=0;i<g->vexnum;i++)
        {
            if(g->edge[front][i]!=__INT_MAX__&&!visited[i])
            {
                visited[i]=true;
                queuePush(&q,i);
            }
        }
    }
    freeQueue(&q);
}

void BFS(Graph* g)
{
    bool* visited=malloc(sizeof(bool)*g->vexnum);
    for(int i=0;i<g->vexnum;i++)
    {
        visited[i]=false;
    }
    Queue q;
    initQueue(&q);
    for(int i=0;i<g->vexnum;i++)
    {
        if(!visited[i])
        {
            _BFS(g,i,visited);
        }
    }
    free(visited);
}


int main() {
    Graph g;
    char labels[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    initGraph(&g, labels, 9, 10);
    addedge(&g, 'A', 'B', 1);
    addedge(&g, 'A', 'C', 3);
    addedge(&g, 'B', 'D', 5);
    addedge(&g, 'B', 'E', 10);
    addedge(&g, 'C', 'F', 20);
    addedge(&g, 'C', 'G', 3);
    addedge(&g, 'D', 'H', 2);
    addedge(&g, 'E', 'I', 6);
    addedge(&g, 'F', 'G', 9);
    addedge(&g, 'H', 'I', 11);
    PrintGraph(&g);
    printf("Depth-First Search (DFS) Traversal:\n");
    DFS(&g);
    printf("\n\nBreadth-First Search (BFS) Traversal:\n");
    BFS(&g);

    return 0;
}