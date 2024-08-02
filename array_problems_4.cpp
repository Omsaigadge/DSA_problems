#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

//problems covered
//1.find pair of elements with sum k in a given array
//2.using hash array
//3.using hashmap
//4.pure logic after sorting


int max(int arr[],int n)
{   
    int max_element=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max_element) max_element=arr[i];
    }

    return max_element;
}

void find_pair_with_sum_k(int arr[],int k,int n)
{
    // int num1,num2;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==k)
            {
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
}

void find_pair_with_hash_approach(int arr[],int k,int n)
{
    int max_element=max(arr,n);

    int temp[max_element];

    for(int i=0;i<n;i++)
    {
        if((k-arr[i])>0)
        
            if(temp[abs(k-arr[i])]>1)
        {
            cout<<arr[i]<<"+"<<k-arr[i]<<"="<<k<<endl;
        }
        temp[arr[i]]++;
    
    }
}

vector<int> find_pairs_hashmap(int arr[],int n,int k)
{
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        int num=arr[i];
        int rem=k-num;

        if(mpp.find(rem)!=mpp.end())
        {
            return {mpp[rem],i};
        }
        mpp[num]=i;
    }
    return {-1,-1};
}

void find_pairs_for_sorted(int arr[],int n,int k)
{
int i=0,j=n-1;
    while(i<j)
    {
        if(arr[i]+arr[j]==k)
        {
            cout<<arr[i]<<" "<<arr[j]<<endl;
            i++;
            j--;
        }
        else if(arr[i]+arr[j]<k)i++;
        else j--;
    }
}

int main()
{
    int A[10]={6,3,8,10,16,7,5,2,9,14};

    int k=10;

    find_pair_with_sum_k(A,k,10);
    find_pair_with_hash_approach(A,k,10);

    vector<int> ans=find_pairs_hashmap(A,k,10);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    int B[10]={1,3,4,5,6,8,9,10,12,14};
    find_pairs_for_sorted(B,10,k);

    return 0;
}