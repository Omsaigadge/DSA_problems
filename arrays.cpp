#include<stdio.h>
#include<iostream>

using namespace std;

void resizing_an_array(int n)
{
    //old array with some elements needs to be resized
    int *p=new int[5];

    //create a new array with required new size
    int *q=new int[10];

    //transfer the elements from older array to new array
    for(int i=0;i<n;i++)
    {
        q[i]=p[i];
    }

    //delete older array by freeing space to the pointed address
    delete []p;

    //point the older pointer to the new created pointer that is pointing to the new array
    q=p;

    //delete new pointer, now all data is transferred to the new array and old pointer is retrieved
    q=NULL;
}


int main()
{
    //types of declaration of array
    //pre-declaration
    int a[5]={1,2,3,4,5};
    //empty spaces are filled with 0
    int b[5]={1,2};
    //if size not specified then based on number of elements, size will be automatically given
    int c[]={1,2,3,4,5,6};
    cout<<a[1]<<endl;
    cout<<2[b]<<endl;
    cout<<*(c+2)<<endl;
    return 0;
}

