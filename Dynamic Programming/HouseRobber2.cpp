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
        if(nums.size()==1) return nums[0];
        vector<int>temp1(nums.begin()+1,nums.end());
        vector<int>temp2(nums.begin(),nums.end()-1);
        int dp[nums.size()];
        memset(dp,-1,sizeof(dp));
        int ans1=solve(temp1.size()-1,temp1,dp);
         memset(dp,-1,sizeof(dp));
        int ans2=solve(temp2.size()-1,temp2,dp);
        return max(ans1,ans2);
    }
};