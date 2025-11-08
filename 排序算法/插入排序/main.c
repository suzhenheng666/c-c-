#include<stdio.h>
#include<stdlib.h>

void insertSort(int* arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int tmp=arr[i];
        int j=i-1;
        while(j>=0)
        {
            if(tmp<arr[j])
            {
                arr[j+1]=arr[j];
                j--;
            }
            else
            {
                break;
            }
        }
        arr[j+1]=tmp;
    }
}

int main()
{
    int arr[]={3,7,1,6,2,9,3};
    int n=sizeof(arr)/sizeof(int);
    insertSort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}