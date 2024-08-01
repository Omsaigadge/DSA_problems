#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

//problems covered
//1.finding duplicates in a sorted array, normal logic
//2.finding duplicates in a sorted array using hash table
//3.finding duplicates in an unsorted array,normal logic
//4.finding duplicates in an unsorted array using hash table
//(for problems 2 and 4, same code applies)


int max(int arr[],int n)
{   
    int max_element=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max_element) max_element=arr[i];
    }

    return max_element;
}

void find_duplicates(int arr[],int n)
{
    int last_duplicate=0;
    for(int i=0;i<n-2;i++)
    {
        if(arr[i]==arr[i+1] && arr[i]!=last_duplicate) 
        {   
            cout<<arr[i]<<endl;
            last_duplicate=arr[i];
        }
    }
}

void count_duplicates(int arr[],int n)
{
    int j=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            j=i+1;
            while(arr[j]==arr[i])j++;

            cout<<arr[i]<<" is repeating "<<j-i<<" times."<<endl;
            i=j-1;
        }
    }
}
void count_duplicates_unsorted(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int count=1;
        if(arr[i]!=-1)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]==arr[j])
                {
                    count++;
                    arr[j]=-1;
                }
            }

            if(count>1)
            cout<<arr[i]<<" has repeated "<<count<<" times"<<endl;
        }

    }
}

void count_duplicates_hash_approach(int arr[],int n)
{
    int max_element=max(arr,n);

    int temp[max_element]={0};

    for(int i=0;i<n;i++)
    {
        temp[arr[i]]++;
    }

    for(int i=0;i<max_element;i++)
    {
        if(temp[i]>1)
        {
            cout<<i<<" has repeated "<<temp[i]<<" times."<<endl;
        }
    }
}

int main()
{
    int A[10]={1,2,2,5,6,7,8,8,8,11};
    cout<<"These are the duplicates:"<<endl;
    find_duplicates(A,10);

    cout<<"Duplicates and their count using method 1:"<<endl;
    count_duplicates_hash_approach(A,10);

    cout<<"Duplicates and their count using method 2:"<<endl;
    count_duplicates(A,10);

    cout<<"Count of duplicates in an unsorted array:"<<endl;
    int B[10]={3,1,4,2,5,3,7,4,3,7};
    count_duplicates_unsorted(B,10);

    return 0;
}