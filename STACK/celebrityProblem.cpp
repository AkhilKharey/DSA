//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        stack<int>st;
        for(int i=0;i<n;i++)
        st.push(i);
        while(st.size()!=1)
        {
            int temp1=st.top();
            st.pop();
            int temp2=st.top();
            st.pop();
            // if temp1 knows temp2 and temp 2 doesnt know temp1,then temp2 could be the  celebrity
            if(M[temp1][temp2]==1 && M[temp2][temp1]==0) 
            st.push(temp2);
            // if temp2 knows temp1 and temp1 doesnt know temp2,temp1 could be the celebrity;
            if(M[temp2][temp1]==1 && M[temp1][temp2]==0)
            st.push(temp1);
            
        }
        int celeb=st.top();
        // now the top element is the only one which could be our celebrity so we need to check the cases.
        for(int i=0;i<n;i++)
        {
            if(M[celeb][i]==1)
            return -1;
        }
        for(int i=0;i<n;i++)
        {
            if(celeb==i)
            continue;
            if(M[i][celeb]==0)
            return -1;
        }
        return celeb;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends