//{ Driver Code Starts 
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------------------------------- recursive approach 

// } Driver Code Ends
class Solution {
    private:
    int solve(vector<int>&height,int ind,int k)
    {
        if(ind==0) return 0;
        int minSteps=INT_MAX;
        int jump;
        for(int j=1;j<=k;j++)
        {
            if(ind-j>=0)
             jump=solve(height,ind-j,k)+abs(height[ind]-height[ind-j]);
            minSteps=min(minSteps,jump);
        }
        return minSteps;
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        return solve(height,n-1,k);
    }
};
// 
// 
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------------------memoization
// } Driver Code Ends
class Solution {
    private:
    int solve(vector<int>&height,int ind,int k,int dp[])
    {
        if(ind==0) return 0;
        int minSteps=INT_MAX;
        int jump;
        if(dp[ind]!=-1) return dp[ind];
        for(int j=1;j<=k;j++)
        {
            if(ind-j>=0)
             jump=solve(height,ind-j,k,dp)+abs(height[ind]-height[ind-j]);
            minSteps=min(minSteps,jump);
        }
        return dp[ind]=minSteps;
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        return solve(height,n-1,k,dp);
    }
};

//{ Driver Code Starts.
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------------------------tabulation with O(n)space complexity
// } Driver Code Ends
class Solution {
   
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        int dp[n+1];
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            int minStep=INT_MAX;
            for(int j=1;j<=k;j++)
            {
                if(i-j>=0)
                {
                    int jump=dp[i-j]+abs(height[i]-height[i-j]);
                    minStep=min(minStep,jump);
                }
            }
            dp[i]=minStep;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
