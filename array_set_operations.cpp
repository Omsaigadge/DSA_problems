#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>
#include<set>

using namespace std;

//questions covered
//1. union
//2. intersection
//3. difference
//4. membership- meaning...it checks whether elements are present, therefore just a search function will work the same4
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
}

void display_vector(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" "<<endl;
    }
}

vector<int> union_of_sorted_arrays(int arr1[],int arr2[],int n,int m)
{
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

vector<int> intersection_of_sorted_arrays(int arr1[],int arr2[],int n,int m)
{
    vector<int> inter;

    int i=0,j=0;

    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j]){i++;}
        else if(arr1[i]>arr2[j]){j++;}
        else
        {
            inter.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return inter;
}

int main()
{
    int A[5]={2,3,5,6,7};
    int B[5]={5,7,9,11,14};
    int n1=sizeof(A)/sizeof(A[0]);
    int n2=sizeof(B)/sizeof(B[0]);
    cout<<n1<<" "<<n2<<endl;
    vector<int> C=union_of_sorted_arrays(A,B,n1,n2);
    
    for(auto & val: C)
        {cout<<val<<" ";}

    cout<<endl;
    // int n3=n1+n2;
    // int C[n3];

    vector<int> D=intersection_of_sorted_arrays(A,B,n1,n2);

    for(auto & val: D)
        cout<<val<<" ";
    
    // display_vector(C);
    // display(C,n3);
    
    return 0;
}