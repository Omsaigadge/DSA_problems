#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int find_summation(int n)
{
    return n*(n+1)/2;
}

int find_missing_element(int arr[],int n)
{
    int sum1=0;
    for(int i=0; i<n; i++)
    {
        sum1+=arr[i];
    }
    int sum2=find_summation(n);
    cout<<sum1<<endl;
    // cout<<sum2<<endl;
    return abs(sum1-sum2);
}



int missing_element_any_start(int arr[],int n)
{
    int sum1=0;
    for(int i=0; i<n; i++)
    {
        sum1+=arr[i];
    }

    return abs(sum1-find_summation(arr[n-1])+find_summation(arr[0]-1));
}

void missing_element_any_start_logic2(int arr[],int n)
{
    int low=arr[0];
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]-i!=low)
         {
             cout<<arr[i]-1<<endl;
             break;
         }
    }
}

void multiple_element_any_start_logic(int arr[],int n)
{
    int diff=arr[0];

    for(int i=0;i<n;i++)
    {
        if(arr[i]-i!=diff)
        {
            while(diff<(arr[i]-i))
            {
                cout<<i+diff<<endl;
                diff++;
            }
        }
    }
}

int max(int arr[],int n)
{   
    int max_element=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max_element) max_element=arr[i];
    }

    return max_element;
}

void multiple_element_any_start_logic2(int arr[],int n)
{
    int max_element=max(arr,n);
    int temp[max_element]={0};
    for(int i=0;i<n;i++)
    {
        temp[arr[i]]++;
    }

    for(int i=1;i<max_element;i++)
    {
        if(temp[i]==0)cout<<i<<endl;
    }
}

int main()
{
    int A[5]={5,6,8,9,10};
    int n=sizeof(A)/sizeof(A[0]);

    // cout<<n<<endl;
    missing_element_any_start_logic2(A,n);
    
    int B[11]={6,7,8,9,11,12,15,16,17,18,19};
    int n2=sizeof(B)/sizeof(B[0]);
    multiple_element_any_start_logic(B,n2);

    multiple_element_any_start_logic2(B,n2);
    return 0;

}