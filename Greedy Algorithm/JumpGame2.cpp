// https://leetcode.com/problems/jump-game-ii/description/
// -----------------------------------------------------------recursive approach(tle)
class Solution
{
private:
    int solve(int index, int jumps, vector<int> &nums)
    {
        if (index >= nums.size() - 1)
            return jumps;
        int mini = INT_MAX;
        for (int i = 1; i <= nums[index]; i++)
        {
            mini = min(mini, solve(index + i, jumps + 1, nums));
        }
        return mini;
    }

public:
    int jump(vector<int> &nums)
    {
        return solve(0, 0, nums);
    }
};
// -------------------------------------------dp solution again tle
class Solution
{
private:
    int solve(int index, int jumps, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (index >= nums.size() - 1)
            return jumps;
        if (dp[index][jumps] != -1)
            return dp[index][jumps];
        int mini = INT_MAX;
        for (int i = 1; i <= nums[index]; i++)
        {
            mini = min(mini, solve(index + i, jumps + 1, nums, dp));
        }

        return dp[index][jumps] = mini;
    }

public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        a
            vector<vector<int>>
                dp(n, vector<int>(n, -1));
        return solve(0, 0, nums, dp);
    }
};
// greedy O(n) approach
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int l = 0, r = 0, jumps = 0;
        int n = nums.size();
        while (r < n - 1)
        {
            int farthest = 0;
            for (int i = l; i <= r; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};