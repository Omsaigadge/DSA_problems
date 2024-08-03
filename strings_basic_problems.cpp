#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>
#include<string>

using namespace std;

//problems covered
//1.finding length of string using function and STL
//2.change string to upper case, lower case, camel case and snake case
//3.check if string is valid, here checking for special characters
//4.reverse string using function and STL
//5.finding frequency of string


void length_of_string(string str)
{
    int len=0;
    while(str[len]!='\0')
    {
        len++;
    }
    cout<<len<<endl;
}


//for all the below operations we will be using ascii codes
void change_case_to_upper(string str)//all capital
{
    for(int i=0;i<str.length();i++)
    {
        if(int(str[i])>=97)
        str[i]=char(int(str[i]-32));
    }
    cout<<str<<endl;
}

void change_case_to_lower(string str)//all lower
{
    for(int i=0;i<str.length();i++)
    {
        if(int(str[i])<=97 && int(str[i])>=65)
        str[i]=char(int(str[i]+32));
    }
    cout<<str<<endl;
}

void change_case_to_camel(string str)//remove spaces, merge words and make all first letters of words captial
{
    for(int i=0;i<str.length()-1;i++)
    {
        if(str[i]==' ')
        {
            str[i+1]=char(int(str[i+1])-32);
        }
    }

    int count=0;
    for (int i = 0; str[i]; i++)
        {
            if (str[i] != ' ')
            {str[count++] = str[i];}
        
        } // here count is
                                   // incremented
    str[count] = '\0';

    for(int i=0;i<count;i++)
    {
        cout<<str[i];
    }
}

void snake_case(string str)//"this is an example" become this_is_an_example
{
    for(int i=0;i<str.length()-1;i++)
    {
        if(str[i]==' ')
        {
            str[i+1]=char(int(str[i+1])-32);
            str[i]='_';
        }
    }
    cout<<str<<endl;
}

int valid_string(const std::string& str)
{
    for(int i = 0; i < str.size(); i++)
    {
        if(!(isupper(str[i]) || islower(str[i]) || isdigit(str[i])))
            return 0;
    }
    return 1;
}

void string_reverse(string str)
{
    int i=0,j=str.length()-1;
    while(i<j)
    {
        swap(str[i],str[j]);
        i++;
        j--;
    }
    cout<<str<<endl;
}

void find_duplicates(string str)
{
    int temp[26]={0};

    for(int i=0;i<str.length();i++)
    {
        temp[int(str[i])%97]++;
    }

    for(int i=0;i<26;i++)
    {
        if(temp[i]>1)
        {
            cout<<char(i+97)<<" has occured "<<temp[i]<<" times"<<endl;
        }
    }
}

//recent compilers do not allow mutable strings, so avoid using pointers
//or try storing it in some variable before using it
int main()
{
    char temp='A';
    string str="This is an example of a string";

    char name[]={'a','b','c','\0'};
    cout<<name<<endl;

    string str2="123str444";
    length_of_string(str);
    cout<<str.length()<<endl;

    cout<<str<<endl;
    cout<<"After conversion to upper:"<<endl;
    change_case_to_upper(str);

    string low="UPPER CASE";
    cout<<low<<endl;
    cout<<"After conversion to lower:"<<endl;
    change_case_to_lower(low);

    cout<<"Changing to camel case:"<<endl;
    change_case_to_camel(str);
    cout<<endl;

    cout<<"changing to snake case:"<<endl;
    snake_case(str);
    cout<<endl;

    cout<<"Check if string is valid:"<<endl;
    cout<<str2<<endl;
    if(valid_string(str2))cout<<"Valid"<<endl;
    else cout<<"Invalid"<<endl;
    cout<<endl;


    cout<<"Reverse the string:"<<endl;
    string_reverse(str2);

    cout<<"Reverse using STL:"<<endl;
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    cout<<endl;
    
    string str3="aabbbcccfghjiiiiiiiiiiiii";
    cout<<"Finding the duplicates in: "<<str3<<endl;
    find_duplicates(str3);
    cout<<endl;
    
    return 0;
}
