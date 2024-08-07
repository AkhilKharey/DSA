class Solution
{
private:
    int profit(vector<int> &prices, int index, int buy, vector<vector<vector<int>>> &dp, int cap)
    {
        if (index == prices.size())
            return 0;
        if (cap == 0)
            return 0;
        int totalProfit = 0;
        if (dp[index][buy][cap] != -1)
            return dp[index][buy][cap];
        if (buy)
        {

            int ifBuyProfit = -prices[index] + profit(prices, index + 1, 0, dp, cap);
            int ifNotBuyProfit = 0 + profit(prices, index + 1, 1, dp, cap);
            totalProfit = max(ifBuyProfit, ifNotBuyProfit);
        }
        else
        {

            int ifSellProfit = prices[index] + profit(prices, index + 1, 1, dp, cap - 1);
            int ifNotSellProfit = 0 + profit(prices, index + 1, 0, dp, cap);
            totalProfit = max(ifSellProfit, ifNotSellProfit);
        }
        return dp[index][buy][cap] = totalProfit;
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        int index = 0;
        int buy = 1;
        int cap = k;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(101, -1)));
        return profit(prices, index, buy, dp, cap);
    }
};