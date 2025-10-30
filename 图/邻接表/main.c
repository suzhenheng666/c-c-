#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

#define NUM 20

//边结构体
typedef struct AredgeNode
{
    int adjvex;
    struct AredgeNode *nextarc;
} AredgeNode;

//顶点结构体
typedef struct VexNode
{
    char vertex;
    struct AredgeNode *firstarc;
} VexNode, AdjList[NUM];

typedef struct
{
    AdjList adjList;
    int vexnum;
    int edgenum;
} Graph;

void initGraph(Graph *g,char *data,int vertexNum,int edgeNum)
{
    g->vexnum = vertexNum;
    g->edgenum = edgeNum;
    for (int i = 0; i < vertexNum; i++)
    {
        g->adjList[i].vertex = data[i];
        g->adjList[i].firstarc = NULL;
    }
}

int getindex(Graph*g ,char vertex)
{
    for(int i=0;i<g->vexnum;i++)
    {
        if(g->adjList[i].vertex==vertex)
        {
            return i;
        }
    }
    return -1;
}

void addedge(Graph*g ,char vertex1,char vertex2)
{
    int pos1=-1,pos2=-1;
    pos1=getindex(g,vertex1);
    pos2=getindex(g,vertex2);
    assert(pos1!=-1&&pos2!=-1);
    AredgeNode* newNode=(AredgeNode*)malloc(sizeof(AredgeNode));
    newNode->adjvex=pos2;
    newNode->nextarc=g->adjList[pos1].firstarc;
    g->adjList[pos1].firstarc=newNode;
    AredgeNode* newNode2=(AredgeNode*)malloc(sizeof(AredgeNode));
    newNode2->adjvex=pos1;
    newNode2->nextarc=g->adjList[pos2].firstarc;
    g->adjList[pos2].firstarc=newNode2;
}

void printGraph(Graph* g)
{
    for(int i=0;i<g->vexnum;i++)
    {
        printf("%-3d",i);
        printf("%-3c",g->adjList[i].vertex);
        AredgeNode* p=g->adjList[i].firstarc;
        while(p)
        {
            printf("->%-3d",p->adjvex);
            p=p->nextarc;
        }
        printf("\n");
    }
}

void _DFS(Graph* g,int v,bool* visited)
{
    visited[v]=true;
    printf("%c ",g->adjList[v].vertex);
    AredgeNode* p=g->adjList[v].firstarc;
    while(p)
    {
        if(!visited[p->adjvex])
        {
            _DFS(g,p->adjvex,visited);
        }
        p=p->nextarc;
    }
}

void DFS(Graph*g)
{
    bool* visited=malloc(sizeof(bool)*g->vexnum);
    for (int i = 0; i < g->vexnum; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < g->vexnum; i++)
    {
        if(!visited[i])
        {
            _DFS(g,i,visited);
        }
    }
    free(visited);
}

void _BFS(Graph* g,int v,bool*visited)
{
    visited[v]=true;
    Queue q;
    initQueue(&q);
    queuePush(&q,v);
    while(!queueIsEmpty(&q))
    {
        int front=queuePop(&q);
        printf("%c ",g->adjList[front].vertex);
        AredgeNode* p=g->adjList[front].firstarc;
        while(p)
        {
            if(!visited[p->adjvex])
            {
                visited[p->adjvex]=true;
                queuePush(&q,p->adjvex);
            }
            p=p->nextarc;
        }
    }
    freeQueue(&q);
}

void BFS(Graph* g)
{
    bool* visited=malloc(sizeof(bool)*g->vexnum);
    for (int i = 0; i < g->vexnum; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < g->vexnum; i++)
    {
        if(!visited[i])
        {
            _BFS(g,i,visited);
        }
    }
    free(visited);
}

int main() {
    Graph graph;
    char labels[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    initGraph(&graph, labels, 9, 10);
    addedge(&graph, 'A', 'B');
    addedge(&graph, 'A', 'C');
    addedge(&graph, 'B', 'D');
    addedge(&graph, 'B', 'E');
    addedge(&graph, 'C', 'F');
    addedge(&graph, 'E', 'G');
    addedge(&graph, 'F', 'H');
    addedge(&graph, 'G', 'I');
    addedge(&graph, 'D', 'I');
    addedge(&graph, 'H', 'A');
    printGraph(&graph);
    printf("DFS Traversal: ");
    DFS(&graph);
    printf("\nBFS Traversal: ");
    BFS(&graph);
    return 0;
}