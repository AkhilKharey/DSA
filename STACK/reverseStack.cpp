//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void InsertAtBottom(stack<int>& st,int x)
    {
        // insert the element x at bottom of a stack
        if(st.empty())
        {
            
            st.push(x);
            return;
        }
        int temp=st.top();
        st.pop();
        InsertAtBottom(st,x);
        st.push(temp);
        return;
    }
    void reverse(stack<int>& st)
    {
        if(st.empty())    
        return;
        int temp=st.top();
        st.pop();
        reverse(st);
        InsertAtBottom(st,temp);
        return;
    }
    void Reverse(stack<int> &St){
        // vector<int>temp;-----------------------------APPROACH1
        // int size=St.size();
        // for(int i=0;!St.empty();i++)
        // {
        //     temp.push_back(St.top());
        //     St.pop();
        // }
        // // reverse(temp.begin(),temp.end());
        // for(int i=0;i<size;i++)
        // {
        //     St.push(temp[i]);
        // ---------------------------------APPROACH2
        reverse(St);
        }
    };


//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends