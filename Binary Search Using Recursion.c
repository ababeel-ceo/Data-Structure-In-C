#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[],int start,int end,int target)
{
    if(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]<target)
            return  binarySearch(arr,mid+1,end,target);
        else if(arr[mid]>target)
            return  binarySearch(arr,start,mid-1,target);
        else
            return  mid;
    }

    return -1;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    printf("%d", binarySearch(a,0,8,91));
    return 0;
}
