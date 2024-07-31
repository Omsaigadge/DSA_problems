#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

// void fun1(int n)
// {
//     if(n>0)
//     {
//     // cout<<n<<endl;
//     fun1(n-1);
//     cout<<n<<endl;
//     }
// }

// int main()
// {
//     int n=3;
//     fun1(n);
//     return 0;

// }

// int static_var(int n)
// {
//     static int x=0;
//     if(n>0)
//     {
//         x++;
//         return (static_var(n-1)+x);
//     }
//     return 0;
// }

// int main()
// {
//     int n=5;
//     cout<<static_var(n);
//     return 0;
// }


//tail recursion in the form of a loop

void tail_recursion(int n)
{
    if(n>0)
    {
        cout<<n<<endl;
        tail_recursion(n-1);
    }
}

void tree_recursion(int n)
{
    if(n>0)
    {
        cout<<n<<endl;
        tree_recursion(n-1);
        tree_recursion(n-1);
    }
}


//indirect recursion examples
void indirect_recursion_fun1(int n);
void indirect_recursion_fun2(int n);

void indirect_recursion_fun1(int n)
{
    if(n>0)
    {
        cout<<n<<endl;
        indirect_recursion_fun2(n-1);
    }
}

void indirect_recursion_fun2(int n)
{
    if(n>1)
    {
        cout<<n<<endl;
        indirect_recursion_fun1(n/2);
    }
}

int nested_recursion(int n)
{
    if(n>100)
    {
        return (n-10);
    }
    else
    {
        return nested_recursion(nested_recursion(n+11));
    }
}
int main()
{
    // int n=5;
    // tail_recursion(n);

    // cout<<"tail recursion ends here"<<endl;
    // for(int i=5;i>0;i--)
    // {
    //     cout<<i<<endl;
    // }
    // return 0;
    // int n=3;
    // tree_recursion(n);
    // return 0;

    // int n=20;
    // indirect_recursion_fun1(n);
    // return 0;

    int n=95;
    cout<<nested_recursion(95); 
    return 0;
}