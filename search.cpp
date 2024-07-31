#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int binarysearch(int arr[],int low,int high,int key)
{
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    return -1;
}

int linearsearch(int arr[],int key,int n)
{
    for(int i=0;i<n;i++)
    {
        if(key==arr[i])
        {
            return i;
        }
    }
    return -1;
}

int max(int arr[],int n)
{
    int max_element=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max_element)
        {
            max_element=arr[i];
        }
    }
    return max_element;
}

int min(int arr[],int n)
{
    int min_element=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min_element)
        {
            min_element=arr[i];
        }
    }
    return min_element;
}

int sum(int arr[],int n)
{
    int sum_of_array=0;
    for(int i=0;i<n;i++)
    {
        sum_of_array+=arr[i];
    }
    return sum_of_array;
}

int average(int arr[],int n)
{
    int sum_of_array=sum(arr,n);
    return sum_of_array/n;
}

// void swap(int a,int b)
// {
//     int temp;
//     temp=a;
//     a=b;
//     b=temp;
// }wri

void reverse_array(int *arr,int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

void left_shift(int *arr,int n)
{
for(int i=0;i<n;i++)
{
    arr[i]=arr[i+1];
}
arr[n-1]=0;
}

void left_rotate(int *arr,int n)
{
    int first=arr[0];
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=first;
}

void reverse_function(int arr[],int start, int end)
{
    while(start<=end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void right_shift(int *arr,int n)
{
    for(int i=n-1;i>0;i--)
{
    arr[i]=arr[i-1];
}
arr[0]=0;
}

void right_rotate(int *arr,int n)
{
    int last=arr[n-1];
    for(int i=n-1;i>0;i--)
{
    arr[i]=arr[i-1];
}
arr[0]=last;
}

void rotate_k_times(int *arr,int n,int k)
{
    k=k%n;
    reverse_function(arr,0,k-1);
    reverse_function(arr,k,n-1);
    reverse_function(arr,0,n-1);
    display(arr,n);    
}

int main()
{
    int arr[9]={0,1,2,3,5,6,11,12,16};
    int arr2[9]={3,2,44,56,4,8,6,1,9};

    int key=5;

    int n=sizeof(arr)/sizeof(arr[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);

    cout<<"Linear search starts here..."<<endl;
    int linear_result=linearsearch(arr,key,n);
    if(linear_result==-1){cout<<"Element not present"<<endl;}
    else{cout<<linear_result<<endl;}

    cout<<"operations"<<endl;
    cout<<max(arr2,n2)<<endl;
    cout<<min(arr2,n2)<<endl;
    cout<<sum(arr2,n2)<<endl;
    cout<<average(arr2,n2)<<endl;

    cout<<"Binary search starts here..."<<endl;
    int binary_result=binarysearch(arr,0,n-1,key);
    if(binary_result==-1){cout<<"Element not present"<<endl;}
    else{cout<<binary_result<<endl;}

    cout<<"Reverse array..."<<endl;
    reverse_array(arr2,n2);
    display(arr2,n2);

    cout<<"left shift..."<<endl;
    left_shift(arr2,n2);
    display(arr2,n2);

    cout<<"right shift..."<<endl;
    right_shift(arr2,n2);
    display(arr2,n2);

    cout<<"left rotate..."<<endl;
    left_rotate(arr2,n2);
    display(arr2,n2);

    cout<<"right rotate..."<<endl;
    right_rotate(arr2,n2);
    display(arr2,n2);

    int k=2;
    cout<<"Rotate k times..."<<endl;
    rotate_k_times(arr2,n2,k);
    // display(&temp,n);

    return 0;
}