// ------------------------------------------------------------recursive
class Solution {
    private:
     int solve(int idx,vector<int>&nums)
     {
        if(idx==0) return nums[idx];
        if(idx<0) return 0;
        int pick =nums[idx]+solve(idx-2,nums);
        int notPick=0+solve(idx-1,nums);
        return max(pick,notPick);
     }
public:
    int rob(vector<int>& nums) {
   return solve(nums.size()-1,nums);   
  }
};
// --------------------------------------------------------------memoization
class Solution {
    private:
     int solve(int idx,vector<int>&nums,int dp[])
     {
        if(idx==0) return nums[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick =nums[idx]+solve(idx-2,nums,dp);
        int notPick=0+solve(idx-1,nums,dp);
        return dp[idx]=max(pick,notPick);
     }
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()];
        memset(dp,-1,sizeof(dp));
   return solve(nums.size()-1,nums,dp);   
  }
};
// ------------------------------------------------------------------------tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()+1];
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int pick=nums[i];
            if(i>=2)
             pick+= dp[i-2];
            int nonPick=0+dp[i-1];  
            
            dp[i]=max(pick,nonPick);
        }
        return dp[nums.size()-1];
    }
};