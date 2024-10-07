// https://leetcode.com/problems/coin-change/description/
class Solution
{
public:
    int solve(int index, vector<int> &coins, int target, vector<vector<int>> &dp)
    {
        // base case think like when we reach the 0th index and there is  a array that consist of only one element
        if (index == 0)
        {
            if (target % coins[index] == 0)
                return target / coins[index];
            return 1e9;
        }
        if (dp[index][target] != -1)
            return dp[index][target];
        // if we not take the current coin then we move to the next index without changing the target
        int notTake = 0 + solve(index - 1, coins, target, dp);
        int take = INT_MAX;
        // if we take it must first satisfy a condition and after that we remain on the same index and substract the target
        if (coins[index] <= target)
            take = 1 + solve(index, coins, target - coins[index], dp);
        // we return the minimum of the take and not take
        return dp[index][target] = min(take, notTake);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int index = coins.size() - 1;
        vector<vector<int>> dp(index + 1, vector<int>(amount + 1, -1));
        int ans = solve(index, coins, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};