#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}


//霍尔法
int paration1(int* arr,int start,int end)
{
    int left=start;
    int right=end;
    while(left<right)
    {
        while(left<right && arr[right]>=arr[start])
        {
            right--;
        }
        while(left<right && arr[left]<=arr[start])
        {
            left++;
        }
        if(left < right)
        {
            swap(&arr[left],&arr[right]);
        }
    }
    swap(&arr[start],&arr[left]);
    return left;
}

//挖坑法
int paration2(int* arr,int start,int end)
{
    int tmp=arr[start];
    int left=start;
    int right=end;
    while(left<right)
    {
        while(left<right && arr[right]>=tmp)
        {
            right--;
        }
        if(left<right)
        {
            arr[left]=arr[right];
        }
        while(left<right && arr[left]<=tmp)
        {
            left++;
        }
        if(left<right)
        {
            arr[right]=arr[left];
        }
    }
    arr[left]=tmp;
    return left;
}

//双指针法
int paration3(int* arr,int start,int end)
{
    int pre=start;
    int cur=start+1;
    while(cur<=end)
    {
        if(arr[cur]<arr[start] && ++pre!=cur)
        {
            swap(&arr[pre],&arr[cur]);
        }
        cur++;
    }
    swap(&arr[start],&arr[pre]);
    return pre;
}

void quickSort(int *arr,int start,int end)
{
    if(start>=end) return;
    int pos=paration3(arr,start,end);
    quickSort(arr,start,pos-1);
    quickSort(arr,pos+1,end);
}

int main()
{
    int arr[]={3,7,1,6,2,9,3};
    int n=sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}