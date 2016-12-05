#include <bits/stdc++.h>

using namespace std;

int main()
{
   int l,count=0;
   string s;
   cin>>l;
   cin>>s;

   for(int i=0;i<l;i++)
   {
       for(int j=l-1;j>i;j--)
       {
           if(s[i] == s[j])
           {
               count++;
               s[j]='\0';
           }
       }
   }
   cout<<(l-2*count-1);
   return 0;
}
