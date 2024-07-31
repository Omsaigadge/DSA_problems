#include<stdio.h>
#include<iostream>

using namespace std;

//answer=7
int q1(int n)
{
static int i = 1;

    if(n>=5)
        return n;

n = n+i;
i++;
return q1(n);
}

//answer=2 0 4 8 0
int q2(int n,int sum)
{
    int k=0,j=0;
    if(n==0)return;
    k=k%10;
    j=n/10;
    sum=sum/k;
    cout<<k<<endl;
}

//9*9*9*9
int q3(int &x,int c)
{
    c=c-1;
    if(c==0)return 1;
    x=x+1;
    return q3(x,c)*x;
}

//answer=51
int q4(int n)
{
    int x=1,k;
    if(n==1)return x;

    for(k=1;k<n;++k)
    {
        x=x+q4(k)*q4(n-k);
    }
    return x;
}

//answer=3 1 2 2 1 3 4 4 4
int q5(int n)
{
    static int d=1;
    cout<<n<<endl;
    cout<<d<<endl;
    d++;
    if(n>1)q5(n-1);
    cout<<d<<endl;
}