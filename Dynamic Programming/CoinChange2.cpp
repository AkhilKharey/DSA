// https://leetcode.com/problems/coin-change-ii/submissions/1389655977/
class Solution
{
public:
    int solve(int index, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            // if the last guy that is the  0th index guy can some up to the target then we
            // will take 1 other wise 0 beccause we are counting the number of ways
            return amount % coins[index] == 0;
        }
        if (dp[index][amount] != -1)
            return dp[index][amount];
        int notTake = solve(index - 1, coins, amount, dp);
        int take = 0;
        if (coins[index] <= amount)
            take = solve(index, coins, amount - coins[index], dp);
        return dp[index][amount] = take + notTake;
    }
    int change(int amount, vector<int> &coins)
    {
        int index = coins.size() - 1;
        vector<vector<int>> dp(index + 1, vector<int>(amount + 1, -1));

        return solve(index, coins, amount, dp);
    }
};