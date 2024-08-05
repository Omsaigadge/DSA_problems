#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// problems covered
// 1. remove outermost parentheses
// 2. check if given 2 strings are anagrams
// 3. check if given strings are isomoprhic

void remove_outermost_parentheses(string str)
{
   int i = 0, count = 0;
   string ans;

   for (int i = 0; i < str.length(); i++)
   {
      if (str[i] == '(')
         count++;
      else
      {
         count--;
      }

      if (count == 1 && str[i] == '(')
         continue;
      else if (count == 0 && str[i] == ')')
         continue;
      else
      {
         ans = ans + str[i];
      }
   }
   cout << ans << endl;
}

bool isAnagram(string s, string t)
{
   int h[26] = {0};
   if (s.length() != t.length())
      return false;

   for (int i = 0; i < s.length(); i++)
   {
      h[(int(s[i]) % 97)]++;
      h[(int(t[i]) % 97)]--;
   }

   for (int i = 0; i < 26; i++)
   {
      if (h[i] != 0)
      {
         return false;
         break;
      }
   }
   return true;
}

bool isIsomorphic(string s, string t)
{
   unordered_map<char, char> m1, m2;

   if (s.length() != t.length())
      return false;
   for (int i = 0; i < s.length(); i++)
   {
      if (m1.count(s[i]))
      {
         if (m1[s[i]] != t[i])
            return false;
      }
      else
      {
         if (m2.count(t[i]))
            return false;

         m1[s[i]] = t[i];
         m2[t[i]] = true;
      }
   }
   return true;
}


int main()
{
   string str = "(()())(())";
   cout << str << endl;
   cout << "After removing outer most parentheses: ";
   remove_outermost_parentheses(str);
   cout << endl;
   // cout<<ans<<endl;

   string s = "foo";
   string t = "car";

   bool ans = isAnagram(s, t);
   if (ans)
   {
      cout << s << " and " << t << " are anagrams" << endl;
   }
   else
   {
      cout << "Nope,not anagrams" << endl;
   }

   bool res=isIsomorphic(s, t);
   if(res)cout<<"isomorphic"<<endl;
   else cout<<"not isomorphic"<<endl;
   return 0;
}