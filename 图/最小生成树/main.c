#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

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

void miniSpanTree_Prim(Graph* g)
{
    int *lowcast=malloc(sizeof(int)*g->vexnum);
    int *adjvex=malloc(sizeof(int)*g->vexnum);
    char *data=malloc(sizeof(char)*g->vexnum);
    int *weights=malloc(sizeof(int)*g->vexnum-1);
    for(int i=0;i<g->vexnum;i++)
    {
        lowcast[i]=g->edge[0][i];
        adjvex[i]=0;
    }
    data[0]=g->data[0];
    lowcast[0]=0;
    for(int i=1;i<g->vexnum;i++)
    {
        int min=INT_MAX;
        int k=0;
        for(int j=1;j<g->vexnum;j++)
        {
            if(lowcast[j]<min&&lowcast[j]!=0)
            {
                min=lowcast[j];
                k=j;
            }
        }
        data[i]=g->data[k];
        lowcast[k]=0;
        weights[i-1]=min;
        printf("(%c,%c)=%d\n",g->data[adjvex[k]],g->data[k],min);
        for(int j=1;j<g->vexnum;j++)
        {
            if(lowcast[j]!=0 && g->edge[k][j]<lowcast[j])
            {
                lowcast[j]=g->edge[k][j];
                adjvex[j]=k;
            }
        }
    }

    
    printf("Path:");
    for(int i=0;i<g->vexnum;i++)
    {
        printf("%c ",data[i]);
    }
    int sum=0;
    for(int i=0;i<g->vexnum-1;i++)
    {
        sum+=weights[i];
    }
    printf("length:%d\n",sum);
    free(data);
    free(weights);
    free(lowcast);
    free(adjvex);
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
    miniSpanTree_Prim(&g);
    return 0;
}