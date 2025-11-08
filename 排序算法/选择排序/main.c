#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void selectSort1(int* arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int j=i+1;
        int min=arr[i];
        int minpos=i;
        for(j;j<n;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                minpos=j;
            }
        }
        arr[minpos]=arr[i];
        arr[i]=min;
    }
}

void selectSort2(int* arr,int n)
{
    int begin=0;
    int end=n-1;
    while(begin<end)
    {
        int minPos=begin;
        int maxPos=begin;
        for(int i=begin;i<=end;i++)
        {
            if(arr[i]<arr[minPos])
            {
                minPos=i;
            }
            if(arr[i]>arr[maxPos])
            {
                maxPos=i;
            }
        }
        swap(&arr[end],&arr[maxPos]); //先交换最大，防止最大值下标为begin
        swap(&arr[begin],&arr[minPos]);
        begin++;
        end--;
    }
}

int main()
{
    int arr[]={3,7,1,6,2,9,3};
    int n=sizeof(arr)/sizeof(int);
    selectSort2(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}