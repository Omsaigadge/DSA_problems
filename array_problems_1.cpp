#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

//questions covered
//1. insert element in a sorted array
//2. check if array is sorted
//3. put all -ve elements on one side
//4. merge 2 sorted arrays into one

void insert_in_sorted_array(int *arr, int n,int x)
{
    int i=n-1;
    while(i>=0 && arr[i]>x)
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=x;
    // *n=*n+1;
}

bool check_if_array_is_sorted(int A[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        if(A[i]>A[i+1])
        {
            return false;
        }
    }
    return true;
}


void arrange_negative_elements_to_one_side(int *arr,int n)
{
    int i=0;
    int j=n-1;

    while(i<j)
    {
        while(arr[i]<0)
        {i++;}

        while(arr[j]>=0)
        {j--;}

        swap(arr[i],arr[j]);
    }
}

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
}

void merge_arrays(int arr1[],int n1,int arr2[],int n2, int *arr3)
{
    //    int n1=sizeof(arr1)/sizeof(arr1[0]);
    // int n2=sizeof(arr2)/sizeof(arr2[0]);
    // int n3=
    int i=0,j=0,k=0;
    // k=n1+n2;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j]){arr3[k++]=arr1[i++];}
        else{arr3[k++]=arr2[j++];}
    }

    for(;i<n1;i++)
    {
        arr3[k++]=arr1[i];
    }

    for(;j<n2;j++)
    {
        arr3[k++]=arr1[j];
    }
}

int main()
{
    int A[10]={3,5,6,7,11,17,22,25,30};
    int x=15;
    int n=sizeof(A)/sizeof(A[0]);

    // insert_in_sorted_array(A,n,x);
    // display(A,n);

    // bool ans=check_if_array_is_sorted(A,n);
    // cout<<ans<<endl;

    // int B[10]={3,5,-6,7,-11,17,-22,-25,30,-15-25};
    int B[10]={-25,-22,-15,-11,-6,3,5,7,17,30};
    int n2=sizeof(B)/sizeof(B[0]);
    // arrange_negative_elements_to_one_side(B,n2);
    // sort(B,n2);
    // display(B,n2);
    int C[20]={};
    merge_arrays(A,n,B,n2,C);
    int n3=n+n2;
    display(C,n3);
    return 0;

}
