#include<stdio.h>

void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}


void adjstDown(int* arr,int n,int parent)
{
    int child=parent*2+1;
    while(child<n)
    {
        if(child+1<n && arr[child+1]>arr[child])
        {
            child++;
        }
        if(arr[parent]<arr[child])
        {
            swap(&arr[parent],&arr[child]);
            parent=child;
            child=parent*2+1;
        }
        else
        {
            break;
        }
    }
}

void heapSort(int* arr,int n)
{
    for(int i=(n-1-1)/2;i>=0;i--)
    {
        adjstDown(arr,n,i);
    }
    int end=n-1;
    while(end>0)
    {
        swap(&arr[end],&arr[0]);
        adjstDown(arr,end,0);
        end--;
    }
}

int main()
{
    int arr[]={3,7,1,6,2,9,3};
    int n=sizeof(arr)/sizeof(int);
    heapSort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
    return 0;
}