#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define NUM 20
typedef struct
{
    char data[NUM];
    int edge[NUM][NUM];
    int vexnum, arcnum;
}Graph;

typedef struct
{
    int node1;
    int node2;
    int weight;
}one_edge;


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

void initedges(Graph* g,one_edge* edges)
{
    int k=0;
    for(int i=0;i<g->vexnum;i++)
    {
        for(int j=i+1;j<g->vexnum;j++)
        {
            if(g->edge[i][j]!=INT_MAX)
            {
                edges[k].node1=i;
                edges[k].node2=j;
                edges[k].weight=g->edge[i][j];
                k++;
            }
        }
    }
}

int compare(const void *a,const void *b)
{
    one_edge *p1=(one_edge*)a;
    one_edge *p2=(one_edge*)b;
    return p1->weight-p2->weight;
}

int find(int *parent,int v)
{
    while(parent[v]!=-1)
    {
        v=parent[v];
    }
    return v;
}

void kruskal(Graph* g)
{
    int *parent=malloc(sizeof(int)*g->vexnum);
    for(int i=0;i<g->vexnum;i++)
    {
        parent[i]=-1;
    }
    one_edge *edges=malloc(sizeof(one_edge)*g->arcnum);
    initedges(g,edges);
    qsort(edges,g->arcnum,sizeof(edges[0]),compare);
    for(int i=0;i<g->arcnum;i++)
    {
        int a1=find(parent,edges[i].node1);
        int a2=find(parent,edges[i].node2);
        if(a1!=a2)
        {
            printf("(%c,%c)--%d\n",g->data[edges[i].node1],g->data[edges[i].node2],edges[i].weight);
            parent[a1]=a2;
        }
    }
    free(parent);
    free(edges);
}

int main()
{
    Graph g;
    char vertexLabels[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G','H','I'};
    initGraph(&g, vertexLabels, 9, 15);
    addedge(&g, 'A', 'B', 10);
    addedge(&g, 'A', 'F', 11);
    addedge(&g, 'B', 'C', 18);
    addedge(&g, 'B', 'I', 12);
    addedge(&g, 'B', 'G', 16);
    addedge(&g, 'C', 'I', 8);
    addedge(&g, 'C', 'D', 22);
    addedge(&g, 'D', 'G', 24);
    addedge(&g, 'D', 'E', 20);
    addedge(&g, 'D', 'H', 16);
    addedge(&g, 'D', 'I', 21);
    addedge(&g, 'E', 'F', 26);
    addedge(&g, 'E', 'H', 7);
    addedge(&g, 'F', 'G', 17);
    addedge(&g, 'G', 'H', 19);
    PrintGraph(&g);
    kruskal(&g);
    return 0;
}