//   recursive solution
// https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump
  int solve(vector<int>&height,int n)
     {
         if(n==0) return 0;
         int left=solve(height,n-1) + abs(height[n]-height[n-1]);
         if(n>1)
         int right=solve(height,n-2) +abs(height[n]-height[n-2]);
         return min(left,right);
     }
    //  dp with memoization
     class Solution {
    private:
     int solve(vector<int>&height,int n,int dp[])
     {
         if(n==0) return 0;
         if(dp[n]!=-1) return dp[n];
         int left=INT_MAX;int right=INT_MAX;
          left=solve(height,n-1,dp) + abs(height[n]-height[n-1]);
         if(n>1)
          right=solve(height,n-2,dp) +abs(height[n]-height[n-2]);
     
          
         return dp[n]=min(left,right);
     }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int dp[n];
        memset(dp,-1,sizeof(dp));
      return  solve(height,n-1,dp);
    }
};
// dp with tabulation without using recursion stack space
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int dp[n];
        
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            int secondStep=INT_MAX;
           int firstStep=dp[i-1] +  abs(height[i]-height[i-1]);
            if(i>1)
            secondStep=dp[i-2] + abs(height[i]-height[i-2]);
            
            dp[i]=min(firstStep,secondStep);
        }
        return dp[n-1];
    }
};