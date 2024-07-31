#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

// struct rectangle 
// {
//     int length;
//     int breadth;
// };

//initalizing a value and pointing it to the address
// int main()
// {
//     int a=10;
//     int *p;
//     p=&a;
//     cout<<a<<endl;
//     cout<<p<<endl;
//     cout<<*p<<endl;

//     return 0;
// }


//pointer to an array of integers
// int main()
// {
//     int A[5]={0,2,4,6,8};
//     int *p;
//     p=A;

//     for(int i=0;i<5;i++)
//     {
//         cout<<A[i]<<" "<<p[i]<<endl;
//     }

//     return 0;   
// }


//array directly using a pointer by dynamic memory
// int main()
// {
//     int *p;
//     p=new int[5];

//     p[0]=1; p[1]=2; p[2]=3;
//     for(int i=0;i<3;i++)
//     {
//         cout<<p[i]<<endl;
//     }

//     free(p);

//     return 0;
// }


// //size of pointers--irrespective of type of the pointer declared, the size of pointers will be 4 bytes or 8 bytes since they only store addresses
// int main()
// {
//     int *p1,a;
//     char *p2,b;
//     float *p3,c;
//     double *p4,d;
//     struct rectangle *p5,obj;

//     cout<<sizeof(p1)<<" "<<sizeof(a)<<endl;
//     cout<<sizeof(p2)<<" "<<sizeof(b)<<endl;
//     cout<<sizeof(p3)<<" "<<sizeof(c)<<endl;
//     cout<<sizeof(p4)<<" "<<sizeof(d)<<endl;
//     cout<<sizeof(p5)<<" "<<sizeof(obj)<<endl;
//     return 0;
// }


// //creating dynamic variables for a structure using pointers
// int main()
// {
//     struct rectangle *p;
//     p=(struct rectangle *)malloc(sizeof(struct rectangle));
//     p->length=10;
//     p->breadth=5;
//     cout<<p->length<<" "<<p->breadth<<endl;

//     return 0;
// }


// //monolithic program for finding area and parameter
// int main()
// {
//     int length, breadth;
//     cin>>length;
//     cin>>breadth;
//     cout<<"area= "<<length*breadth<<endl<<"perimeter= "<<2*(length+breadth)<<endl;
//     return 0;
// }


// //creating a class in cpp
// class rectangle
// {
//     //defining data members
//     private:
//     int length,breadth;

//     //writing functions
//     public:

//     //default constructor
//     rectangle()
//     {
//         length=breadth=0;
//     }


//     //parameterized constructor
//     rectangle(int l,int b)
//     {
//         length=l;
//         breadth=b;
//     }

//     int area()
//     {
//         return length*breadth;
//     }

//     int perimeter()
//     {
//         return 2*(length+breadth);
//     }

//     void setlength(int l)
//     {
//         length=l;
//     }

//     void setbreadth(int b)
//     {
//         breadth=b;
//     }

//     int getlength(){return length;}

//     int getbreadth(){return breadth;}

//     ~rectangle()
//     {
//         cout<<"destructor"<<endl;
//     }
// };

// int main()
// {
//     rectangle r(10,5);
//     cout<<r.area()<<endl;
//     cout<<r.perimeter()<<endl;
//     r.setlength(20);
//     r.setbreadth(10);
//     cout<<r.getlength()<<" "<<r.getbreadth()<<endl;

//     return 0;

// }


//template class in cpp

template<class T>
class arithmetic
{
private:
    T a;
    T b;

public:
    // arithmetic();
    arithmetic(T a,T b);
    T sum();
    T difference();

};

template<class T>
arithmetic<T>::arithmetic(T a,T b)
{ 
    this->a=a;
    this->b=b;
}


template<class T>
T arithmetic<T>::sum()
{
    T c;
    c=a+b;
    return c;
}

template<class T>
T arithmetic<T>::difference()
{
    T c;
    c=a-b;
    return c;
}


int main()
{
    arithmetic<float> r(10.11,5.546);
    cout<<r.sum()<<" "<<r.difference()<<endl;
}

