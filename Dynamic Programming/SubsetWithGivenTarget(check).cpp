//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
// ---------------------------------------------------recursion
class Solution{   
    private:
    bool f(int index,int target,vector<int>&arr)
    {
        if(target==0) return true;
        if(index==0) return (arr[index]==target);
       
       bool notTake=f(index-1,target,arr);
       bool take=false;
       if(target>=arr[index])
       take=f(index-1,target-arr[index],arr);
       return take||notTake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int k=sum;
        return f(arr.size()-1,k,arr);
    }
};
// ---------------------------------------------------------------memoizaation
class Solution{   
    private:
    bool f(int index,int target,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(target==0) return true;
        if(index==0) return (arr[index]==target);
       if(dp[index][target]!=-1) return dp[index][target];
       bool notTake=f(index-1,target,arr,dp);
       bool take=false;
       if(target>=arr[index])
       take=f(index-1,target-arr[index],arr,dp);
       return dp[index][target]= take||notTake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(arr.size()-1,sum,arr,dp);
        return dp[n-1][sum];
    }
};
// --------------------------------------------------------tabulation
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        // dp[index][target]
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        // base cases from the recursion code
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        dp[0][arr[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool notTake=dp[i-1][target];
              bool take=false;
              if(target>=arr[i])
              take=dp[i-1][target-arr[i]];
              dp[i][target]= take||notTake;
            }
        }
        return dp[n-1][sum];
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends