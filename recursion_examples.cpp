#include<stdio.h>
#include<iostream>

using namespace std;

//preferably, formula is used n*(n+1)/2
int sum_of_n_natural_numbers(int n)
{
    // int sum=0;
    if(n>0)
    {
        // sum=sum+n;
        // sum_of_n_natural_numbers(n-1);
        // // sum=sum+n;
        // // return sum;
        return n+sum_of_n_natural_numbers(n-1);
    }
    return 0;
}

int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n>0)
    {
        return n*factorial(n-1);
    }
    return 0;
}


float power_using_recursion(int m,int n)
{
    float ans=1;
    if(n==0)
    {
        return 1;
    }
    else if(n>0)
    {
        ans=m*power_using_recursion(m,n-1);
        return ans;
    }
    // else if(n<0)
    // {
    //     ans=1/(m*power_using_recursion(m,n-1));
    // }
    return 0;
}


int taylor_series(int n,int x)
{
    static int p=1,f=1;
    int r=0;
    if(n==0)
        return 1;
    else
    {
        r=taylor_series(n-1,x);
        p=p*x;
        f=f*n;
        return r+p/f;
    }
}


int taylor_using_horner(int n,int x)
{
    static int sum=1;
    if(n==0)
        return sum;
    else
    {
        sum=1+sum*x/n;
        return taylor_using_horner(n-1,x);
    }
}

int fibonacci(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1)+ fibonacci(n-2);
    }
}

int fibonacci_using_loop(int n)
{
    int t0=0;
    int t1=1;
    int s=0;
    if(n<=1)return n;

    for(int i=2;i<=n;i++)
    {
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}
int f[10];


//using memoization
int fibonacci_optimized(int n)
{
    
    if(n<=1)
    {
        f[n]=n;
        return n;
    }
    else
    {
        if(f[n-2]==-1)
        {
            f[n-2]=fibonacci_optimized(n-2);
        }

        if(f[n-1]==-1)
        {
            f[n-1]=fibonacci_optimized(n-1);
        }
        return f[n-1]+f[n-2];
    }
    
}

int nCr_formula_using_recursion(int n,int r)
{
    if((n==0 && r==0) || (n==1 && r==1))
        return 1;
    else if(r>0 && r<=n)
    {
        return n*factorial(n-1)/(r*factorial(r-1)*(n-r)*factorial(n-r-1));
    }
}


int nCr_using_pascal_triangle(int n,int r)
{
    if(r==0 || r==n)
        return 1;
    else
        return nCr_using_pascal_triangle(n-1,r-1)+nCr_using_pascal_triangle(n-1,r);
}

int tower_of_hanoi(int n,int A,int B,int C)
{
    if(n>0)
    {
        tower_of_hanoi(n-1,A,C,B);
        printf("from %d to %d",A,C);
        printf("\n");
        tower_of_hanoi(n-1,B,A,C);
    }
}
int main()
{
    int n=5,m=2;
    for(int i=0;i<=n;i++)
    {
        f[i]=-1;
    }
    int A=1,B=2,C=3;
    cout<<sum_of_n_natural_numbers(n)<<endl;
    cout<<factorial(n)<<endl;
    cout<<power_using_recursion(m,n)<<endl;
    cout<<taylor_series(n,m)<<endl;
    cout<<taylor_using_horner(n,m)<<endl;
    cout<<fibonacci(n)<<endl;
    cout<<fibonacci_optimized(n)<<endl;
    cout<<nCr_formula_using_recursion(n,m)<<endl;
    cout<<tower_of_hanoi(n,A,B,C)<<endl;
    return 0;
}