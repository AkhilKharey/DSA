// Input: s = "  hello world  "
// Output: "world hello"
#include<bits/stdc++.h>
using namespace std;
void reverse(string temp)
    {
     int s=0;
     int e=temp.length();
     while(s<e)
     {
         swap(temp[s++],temp[e--]);
     }
     
    }
    string reverseWords(string s) {
      string temp=" ";
      string revstrng=" ";
      for(int i=s.length()-1;i>=0;i--)
      {
        if(s[i]=='\0')
        {
            // reverse(temp);
          
          revstrng=revstrng+temp;
       
        }
        else if(s[i]!='\0')
        {
         temp=temp+s[i];
        }
      }
      return revstrng;
    }
      int main()
      {
       string s;
       getline(cin,s);
       cout<<reverseWords(s);  
      }