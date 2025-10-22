#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int weight;
    int right;
    int left;
    int parent;
} HuffmanNode;

typedef struct
{
    char data;
    char *code;
} HuffmanCode;

void getMinIndexs(HuffmanNode *nodes,int size,int *pos1,int *pos2)
{
    int min1=__INT_MAX__, min2=__INT_MAX__;
    for(int i=1;i<size;i++)
    {
        if(nodes[i].parent==-1 && nodes[i].weight<min1)
        {
            min1=nodes[i].weight;
            *pos1=i;
        }
    }
    for (int i = 1; i < size; i++)
    {
        if (nodes[i].parent == -1 && i != *pos1 && nodes[i].weight < min2)
        {
            min2 = nodes[i].weight;
            *pos2 = i;
        }
    }
}

HuffmanNode* createHuffmanTree(HuffmanNode *nodes, int size, int *weights)
{
    for (int i = 1; i <= size; i++)
    {
        nodes[i].weight = weights[i];
        nodes[i].left = -1;
        nodes[i].right = -1;
        nodes[i].parent = -1;
    }
    for(int i=size+1;i<2*size;i++)
    {
        nodes[i].weight=0;
        nodes[i].left=-1;
        nodes[i].right=-1;
        nodes[i].parent=-1;
    }
    for (int i = size+1; i < 2 * size; i++)
    {
        int pos1=-1, pos2=-1;
        getMinIndexs(nodes,i,&pos1,&pos2);
        nodes[i].weight=nodes[pos1].weight+nodes[pos2].weight;
        nodes[i].left=pos1;
        nodes[i].right=pos2;
        nodes[pos1].parent=i;
        nodes[pos2].parent=i; 
    }
    return nodes;
}

HuffmanCode* getHuffmanCode(HuffmanNode *nodes, int size,char data[])
{
    HuffmanCode* codes=malloc(sizeof(HuffmanCode)*size);
    for(int i=0;i<size;i++)
    {
        codes[i].data=data[i];
        codes[i].code=NULL;
    }
    for (int i = 1; i <= size; i++)
    {
        char *tmp=malloc(sizeof(char)*size);
        tmp[size-1]='\0';
        int codeSize=1;
        int cur=i;
        while(nodes[cur].parent!=-1)
        {
            int parentIndex=nodes[cur].parent;
            if(nodes[parentIndex].left==cur)
            {
                tmp[size-codeSize-1]='0';
            }
            else
            {
                tmp[size-codeSize-1]='1';
            }
            codeSize++;
            cur=parentIndex;
        }
        codes[i-1].code=malloc(sizeof(char)*codeSize);
        codes[i-1].code[codeSize-1]='\0';
        strcpy(codes[i-1].code,tmp+size-codeSize);
        free(tmp);
    }
    return codes;
}

void PrintHuffmanCode(HuffmanCode *codes, int size,char data[])
{
    for(int i=0;i<strlen(data);i++)
    {
        for(int j=0;j<size;j++)
        {
            if(codes[j].data==data[i])
            {
                printf("%s",codes[j].code);
                break;
            }
        }
    }
    printf("\n");
}

void HuffmanDecode(HuffmanNode *nodes, int size, char *encodedStr, char *str)
{
    int root=2*size-1;
    int len=strlen(encodedStr);
    int current=root;
    for(int i=0;i<len;i++)
    {
        if(encodedStr[i]=='0')
        {
            current=nodes[current].left;
        }
        else
        {
            current=nodes[current].right;
        }
        if(nodes[current].left==-1 && nodes[current].right==-1)
        {
            printf("%c",str[current-1]);
            current=root;
        }
    }
}

int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e'};
    int weights[] = {5, 9, 12, 13, 16};
    int size = sizeof(data) / sizeof(data[0]);
    HuffmanNode* nodes =malloc(sizeof(HuffmanNode) * (2 * size));
    nodes = createHuffmanTree(nodes, size, weights);
    HuffmanCode* codes = getHuffmanCode(nodes, size,data);
    char str[]="abaabbcde";
    PrintHuffmanCode(codes, size,str);
    char encodedStr[]="0010100100101011011000";
    printf("Decoded string: ");
    HuffmanDecode(nodes, size, encodedStr, data);


    return 0;
}