#include<stdio.h>

void bubbleSort(int* arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            int k=j+1;
            if(arr[j]>arr[k])
            {
                int tmp=arr[j];
                arr[j]=arr[k];
                arr[k]=tmp;
            }
        }
    }
}

int main()
{
    int arr[]={3,7,1,6,2,9,3};
    int n=sizeof(arr)/sizeof(int);
    bubbleSort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}