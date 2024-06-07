//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool redundant(stack<char>&st,int count)
        {
            //base case
            if(st.top()=='(')
            {
                if(count>0)
                {
                 st.pop();
                 return false;
                }
                else
                {
                    st.pop();
                    return true;
                }
            }
            
            char temp=st.top();
            if(temp=='+'||temp=='*'||temp=='-'||temp=='/')
            count++;
            st.pop();
            redundant(st,count);
            
        }
    int checkRedundancy(string s) {
        // code here
        
         stack<char>st;
         for(int i=0;i<s.length();i++)
         {
             char ch=s[i];
             if(ch=='('||ch=='+'||ch=='*'||ch=='-'||ch=='/')
             {
                 st.push(ch);
             }
             else if(ch==')')
             {
                 int count=0;
                 if(redundant(st,count))
                 return 1;
             }
             
         }
         return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends