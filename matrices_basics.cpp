#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>

using namespace std;

//concepts covered
//1.diagonal matrix
//2. lower triangular matrix
//3. upper triangular matrix

class diagonal
{
    private:
        int *A;
        int n;
        
    public:
        diagonal()
        {
            n=2;
            A=new int[2];
        }

        diagonal(int n)
        {
            this->n=n;
            A=new int[n];
        }
        void set_diagonal(int i,int j,int val);
        int get_diagonal(int i,int j,int val);
        void print_diagonal();


        ~diagonal()
        {
            delete []A;
        }

};

void diagonal::set_diagonal(int i,int j,int val)
{
    if(i==j)
        A[i]=val;
}

int diagonal:: get_diagonal(int i,int j,int val)
{
    if(i==j) return A[i];
    
    return 0;
}

void diagonal:: print_diagonal()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) cout<<A[i];
            else cout<<0;
        }
        cout<<endl;
    }
}

//-----------------------------
class lowertriangle
{
    private:
        int *A;
        int n;
    public:
        lowertriangle()
        {
            n=2;
            A=new int[2*(2+1)/2];
        }

        lowertriangle(int n)
        {
            this->n=n;
            A=new int[n*(n+1)/2];
        }
        void set_lower(int i,int j,int val);
        int get_lower(int i,int j,int val);
        void display_lower();

        ~lowertriangle()
        {
            delete []A;
        }

        
};

void lowertriangle:: set_lower(int i,int j, int val)
{
    if(i>=j)
        A[i*(i-1)/2 + j-1]=val;
}

int lowertriangle:: get_lower(int i,int j,int val)
{
    if(i>=j)
        return A[i*(i-1)/2 + j-1];
    
    return 0;
}

void lowertriangle:: display_lower()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j) cout<<A[i*(i-1)/2 + j-1];
            else cout<<0;
        }
        cout<<endl;
    }
}

//-----------------------------
class uppertriangle
{
    private:
        int *A;
        int n;
    public:
        uppertriangle()
        {
            n=2;
            A=new int[2*(2+1)/2];
        }

        uppertriangle(int n)
        {
            this->n=n;
            A=new int[n*(n+1)/2];
        }

        void set_upper(int i,int j,int val);
        int get_upper(int i,int j,int val);
        void display_upper();

        ~uppertriangle()
        {
            delete []A;
        }
};
void uppertriangle:: set_upper(int i,int j,int val)
{
    if(i<=j)
     A[j*(j-1)/2 + i-1]=val;
}

int uppertriangle:: get_upper(int i,int j,int val)
{
    if(i<=j)
        return A[j*(j-1)/2 + i-1];
    return 0;
}

void uppertriangle:: display_upper()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<=j)
                cout<<A[j*(j-1)/2 + i-1];
            else cout<<0;
        }
        cout<<endl;
    }
}
//----------------
int main()
{
    diagonal m(4);

    cout<<"Diagonal matrix"<<endl;
    m.set_diagonal(0,0,9);
    m.set_diagonal(1,1,5);
    m.set_diagonal(2,2,7);
    m.set_diagonal(3,3,8);
    m.print_diagonal();

    cout<<"Lower triangular matrix"<<endl;
    lowertriangle l(3);
    l.set_lower(1,1,1);
    l.set_lower(2,1,2);
    l.set_lower(3,1,3);
    l.set_lower(2,2,4);
    l.set_lower(3,2,5);
    l.set_lower(3,3,6);
    l.display_lower();
    
    cout<<"Upper triangular matrix"<<endl;
    uppertriangle u(3);
    u.set_upper(1,1,1);
    u.set_upper(1,2,2);
    u.set_upper(1,3,3);
    u.set_upper(2,2,4);
    u.set_upper(2,3,5);
    u.set_upper(3,3,6);
    u.display_upper();

    return 0;
}