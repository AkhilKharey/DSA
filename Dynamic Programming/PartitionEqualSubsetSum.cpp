// https://leetcode.com/problems/partition-equal-subset-sum/
class Solution
{
public:
    bool solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (index == 0)
            return (arr[index] == target);
        if (dp[index][target] != -1)
            return dp[index][target];
        bool notTake = solve(index - 1, target, arr, dp);
        bool take = false;
        if (target >= arr[index])
            take = solve(index - 1, target - arr[index], arr, dp);
        return dp[index][target] = take || notTake;
    }
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (sum % 2)
            return false;
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(nums.size() - 1, target, nums, dp);
    }
};