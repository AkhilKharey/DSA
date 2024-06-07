//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++
// -------------------------------------------------------------------------------approach 1
class Solution{
    
    public:
    void fillvector(stack<int>st,int temp,vector<int> &ans)
    {
        if(st.empty())
        {
        ans.push_back(-1);
        return;
        }
        int x=st.top();
        if(x<temp)
        {
            ans.push_back(x);
            return;
        }
        else
        {
            st.pop();
            fillvector(st,temp,ans);
        }
    }
    void solve(stack<int>&st,vector<int>&ans)
    {
        if(st.empty())
        {
            return;
        }
        int temp=st.top();
        st.pop();
        fillvector(st,temp,ans);
        solve(st,ans);
    }
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        reverse(arr.begin(),arr.end());
        vector<int>ans;
        stack<int>st;
        for(auto &i:arr)
        {
            st.push(i);
        }
        solve(st,ans);
        return ans;
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
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends
// ----------------------------------------------------approach2
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int>ans;
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            int temp=arr[i];
            if(temp>st.top())
            {
                ans.push_back(st.top());
                st.push(temp);
            }
            else {
                while(st.top()>=temp)
                {
                    st.pop();
                }
                ans.push_back(st.top());
                st.push(temp);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    } 
};