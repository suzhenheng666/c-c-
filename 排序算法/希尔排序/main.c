#include<stdio.h>
#include<stdlib.h>

void shell(int* arr,int n,int gap)
{
    for(int i=gap;i<n;i++)
    {
        int tmp=arr[i];
        int j=i-gap;
        while(j>=0)
        {
            if(tmp<arr[j])
            {
                arr[j+gap]=arr[j];
                j-=gap;
            }
            else
            {
                break;
            }
        }
        arr[j+gap]=tmp;
    }
}

void shellSort(int *arr,int n)
{
    int gap=n/3+1;
    while(gap>1)
    {
        gap=gap/3+1;
        shell(arr,n,gap);
    }
}

int main()
{
    int arr[]={3,7,1,6,2,9,3};
    int n=sizeof(arr)/sizeof(int);
    shellSort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}