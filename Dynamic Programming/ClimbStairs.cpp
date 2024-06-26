// memoizaation
class Solution {
public:
     int solve(int n,int dp[])
     {
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int left=solve(n-1,dp);
        int right=solve(n-2,dp);
        return dp[n]=left+right;
     }
    int climbStairs(int n) {
      int dp[n+1];
      memset(dp,-1,sizeof(dp));
     return solve(n,dp);
    }
};
// tabulation without optimizing space
class Solution {
public:
  
     
    int climbStairs(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
// now space optimization to O(1)
class Solution {
public:
  
     
    int climbStairs(int n) {
     int prev2=1;
     int prev=1;
      if(n==0||n==1) return 1;
      int curri=0;
         for(int i=2;i<=n;i++)
         {
         curri=prev2+prev;
         prev2=prev;
         prev=curri;
         }
         return curri;
    }
};