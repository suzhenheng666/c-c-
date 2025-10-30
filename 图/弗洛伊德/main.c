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

void printPath(int parent[][5],int i,int j)
{
    if(i==j)
    {
        printf("%d",i);
        return;
    }
    if(parent[i][j]==-1)
    {
        printf("No Path");
        return;
    }
    printPath(parent,i,parent[i][j]);
    printf("->%d",j);
}

void print(Graph* g,int parent[][5],int dist[][5])
{
    for(int i=0;i<g->vexnum;i++)
    {
        for(int j=0;j<g->vexnum;j++)
        {
            if(i==j)
            {
                continue;
            }
            printf("from %d to %d Path: ",i,j);
            printPath(parent,i,j);
            if(dist[i][j] == INT_MAX)
                printf("      distance:0\n");
            else
                printf("      distance:%d\n", dist[i][j]);
        }
    }
}

void floyd(Graph *g)
{
    int parent[5][5];
    int dist[5][5];
    for(int i=0;i<g->vexnum;i++)
    {
        for(int j=0;j<g->vexnum;j++)
        {
            dist[i][j]=g->edge[i][j];
            if(g->edge[i][j]!=INT_MAX && i!=j)
            {
                parent[i][j]=i;
            }
            else
            {
                parent[i][j]=-1;
            }
        }
    }
    for(int k=0;k<g->vexnum;k++)
    {
        for(int i=0;i<g->vexnum;i++)
        {
            for(int j=0;j<g->vexnum;j++)
            {
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    parent[i][j]=parent[k][j];
                }
            }
        }
    }
    //打印parent矩阵
    printf("     ");
    for(int i=0;i<g->vexnum;i++)
    {
        printf("%-5d",i);
    }
    printf("\n");
    for(int i=0;i<g->vexnum;i++)
    {
    	printf("%-5d",i);
    	for(int j=0;j<g->vexnum;j++)
    	{
    		printf("%-5d",parent[i][j]);
		}
		printf("\n");
	}
    //打印dist矩阵
    print(g,parent,dist);
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
    floyd(&g);
    return 0;
}