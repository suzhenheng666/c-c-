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

void printPath(int *parent,int v)
{
    if(parent[v]==-1)
    {
        printf("%d",v);
        return;
    }
    printPath(parent,parent[v]);
    printf("->%d",v);
}

void print(int *parent,int *v,int start,int n)
{
    printf("Shortest path from the source %d to each vertex:\n",start);
    printf("start\tmdistent\tPath\n");
    for(int i=0;i<n;i++)
    {
        if(start!=i)
        {
            printf("%d\t%d\t",i,v[i]);
            printPath(parent,i);
            printf("\n");
        }
    }

}

void Fute(Graph* g,int start)
{
    int *parent=malloc(sizeof(int)*g->vexnum);
    int *dist=malloc(sizeof(int)*g->vexnum);
    for(int i=0;i<g->vexnum;i++)
    {
        parent[i]=-1;
        dist[i]=INT_MAX;
    }
    dist[start]=0;
    for(int u=0;u<g->vexnum-1;u++)
    {
        for(int i=0;i<g->vexnum;i++)
        {
            for(int j=0;j<g->vexnum;j++)
            {
                if(g->edge[i][j]!=INT_MAX && dist[j]>dist[i]+g->edge[i][j])
                {
                    dist[j]=dist[i]+g->edge[i][j];
                    parent[j]=i;
                }
            }
        }
    }
     for(int i=0;i<g->vexnum;i++)
        {
            for(int j=0;j<g->vexnum;j++)
            {
                if(g->edge[i][j]!=INT_MAX && dist[j]>dist[i]+g->edge[i][j])
                {
                    printf("存在负权环\n");
                    free(parent);
                    free(dist);
                    return;
                }
            }
        }
    print(parent,dist,start,g->vexnum);
    free(parent);
    free(dist);
}


int main()
{
    Graph g;
    char data[]={'s','y','t','z','x'};
    initGraph(&g,data,5,10);
    addedge(&g,'s','y',7);
    addedge(&g,'s','t',6);
    addedge(&g,'y','x',-3);
    addedge(&g,'y','z',9);
    addedge(&g,'t','y',8);
    addedge(&g,'t','x',5);
    addedge(&g,'t','z',-4);
    addedge(&g,'z','x',7);
    addedge(&g,'z','s',2);
    addedge(&g,'x','t',-2);
    PrintGraph(&g);
    Fute(&g,0);
    return 0;
}