//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
            stack<char>st;
        for(auto &ch:x)
        {
             if(ch=='('||ch=='{'||ch=='[')
             {
                 st.push(ch);
             }
             else if(ch==')')
             {
                 if(!st.empty())
                 {

                 
                 if(st.top()=='(')
                 {
                     st.pop();
                 }
                 else
                 {
                     return false;
                 }
                 }
                 else
                 return false;
             }
             else if(ch=='}')
             {
                 if(!st.empty())
                 {

                 
                 if(st.top()=='{')
                 {
                     st.pop();
                 }
                 else
                 {
                     return false;
                 }
                 }
                 else
                 return false;
             }
             else if(ch==']')
             {
                 if(!st.empty())
                 {
                 if(st.top()=='[')
                 {
                     st.pop();
                 }
                 else
                 {
                     return false;
                 }
                 }
                 else
                 return false;
             }
        }
        if(st.empty())
        return true;
        else
        return false;
        
        
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends