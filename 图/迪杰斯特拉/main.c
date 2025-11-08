#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

int minipos(int *v,bool *s,int n)
{
    int min=INT_MAX;
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        if(!s[i] && v[i]<min)
        {
            min=v[i];
            pos=i;
        }
    }
    return pos;
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
    printf("goal\tmdistent\tPath\n");
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

void dijste(Graph *g,int n)
{
    bool *s=malloc(sizeof(bool)*g->vexnum);
    int *v=malloc(sizeof(int)*g->vexnum);
    int *parent=malloc(sizeof(int)*g->vexnum);
    for(int i=0;i<g->vexnum;i++)
    {
        s[i]=false;
        v[i]=INT_MAX;
        parent[i]=-1;
    }
    v[n]=0;
    for(int i=0;i<g->vexnum;i++)
    {
        int u=minipos(v,s,g->vexnum);
        s[u]=true;
        //松弛操作
        for(int j=0;j<g->vexnum;j++)
        {
            if(!s[j] && g->edge[u][j]!=INT_MAX && v[j] > v[u]+g->edge[u][j])
            {
                v[j]=v[u]+g->edge[u][j];
                parent[j]=u;
            }
        }
    }
    print(parent,v,n,g->vexnum);
    free(s);
    free(v);
    free(parent);
}

int main()
{
    char data[5]={'A','B','C','D','E'};
    Graph g;
    initGraph(&g,data,5,10);
    addedge(&g,'A','B',5);
    addedge(&g,'A','C',10);
    addedge(&g,'B','C',3);
    addedge(&g,'B','D',2);
    addedge(&g,'B','E',9);
    addedge(&g,'C','B',2);
    addedge(&g,'C','E',1);
    addedge(&g,'D','A',7);
    addedge(&g,'D','E',6);
    addedge(&g,'E','D',4);
    dijste(&g,0);
    return 0;
}