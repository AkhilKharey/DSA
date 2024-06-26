// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int> &s,int cnt,int size)
    {
        if(cnt==size/2)
        {
            s.pop();
            return;
        }
        int x=s.top();
        s.pop();
        cnt++;
        solve(s,cnt,size);
        s.push(x);
        return;
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        solve(s,0,sizeOfStack);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends