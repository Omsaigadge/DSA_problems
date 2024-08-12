#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> twoSum_2(vector<int>& nums, int target) 
{
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            if(mpp.find(target-num)!=mpp.end())return {i,mpp[target-num]};

            mpp[num]=i;
        }
    return {};

}

vector<int> twoSum_1(vector<int>& nums, int target) 
{
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            if(mpp.find(target-num)!=mpp.end())return {i,mpp[target-num]};

            mpp[num]=i;
        }
    return {};
}

bool isPalindrome_1(int x) 
{
        string str=to_string(x);
        int i=0,j=str.length()-1;
        if(x<0) return false;
        while(i<=j)
        {
            if(str[i]!=str[j])return false;
            else{
                i++;
                j--;
            }
        }
        return true;
}

bool isPalindrome_2(int x) 
{
        string str=to_string(x);
        int i=0,j=str.length()-1;
        if(x<0) return false;
        while(i<=j)
        {
            if(str[i]!=str[j])return false;
            else{
                i++;
                j--;
            }
        }
        return true;
}

int romanToInt(string s) 
{
        unordered_map<char , int> mpp{
            {'I' , 1},{'V' , 5},{'X' , 10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int num=0;
        for(int i=0; i< s.length(); ++i){
             if(mpp[s[i]] < mpp[s[i+1]]){
                num += (mpp[s[i+1]] - mpp[s[i]]);
                ++i;
                }   
             else
              num += mpp[s[i]];
        }
        return num;
        
}

int main()
{   
    vector<int> nums;
    nums={1,3,12,4,7,6,9,6};
    int target=11;
    return 0;
}