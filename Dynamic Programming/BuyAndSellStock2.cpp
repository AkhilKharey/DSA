// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// ----------------------------------------------------------------------recursive
// tc-2^n
// sc-n
class Solution
{
private:
    int profit(vector<int> &prices, int index, int buy)
    {
        if (index == prices.size())
            return 0;
        int totalProfit = 0;
        if (buy)
        {
            // it mean you can buy now because you have not bought previously
            // now its up to you wether to buy or not
            // if buy then we canot buy again so mark buy as 0
            int ifBuyProfit = -prices[index] + profit(prices, index + 1, 0);
            int ifNotBuyProfit = 0 + profit(prices, index + 1, 1);
            totalProfit = max(ifBuyProfit, ifNotBuyProfit);
        }
        else
        {
            // you can sell because you have bought
            //  previously now its up to you wether to sell or not
            int ifSellProfit = prices[index] + profit(prices, index + 1, 1);
            int ifNotSellProfit = 0 + profit(prices, index + 1, 0);
            totalProfit = max(ifSellProfit, ifNotSellProfit);
        }
        return totalProfit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int index = 0;
        int buy = 1;
        // buy=1 means you can buy and 0 means you cannot buy
        // as youb have previously bought before
        return profit(prices, index, buy);
    }
};
// --------------------------------------------------------------------------------memoization
// TC-O(N*2) SC-O(N*2)+O(N)
class Solution
{
private:
    int profit(vector<int> &prices, int index, int buy, vector<vector<int>> &dp)
    {
        if (index == prices.size())
            return 0;
        int totalProfit = 0;
        if (dp[index][buy] != -1)
            return dp[index][buy];
        if (buy)
        {
            // it mean you can buy now because you have not bought previously
            // now its up to you wether to buy or not
            // if buy then we canot buy again so mark buy as 0
            int ifBuyProfit = -prices[index] + profit(prices, index + 1, 0, dp);
            int ifNotBuyProfit = 0 + profit(prices, index + 1, 1, dp);
            totalProfit = max(ifBuyProfit, ifNotBuyProfit);
            dp[index][buy] = totalProfit;
        }
        else
        {
            // you can sell because you have bought
            //  previously now its up to you wether to sell or not
            int ifSellProfit = prices[index] + profit(prices, index + 1, 1, dp);
            int ifNotSellProfit = 0 + profit(prices, index + 1, 0, dp);
            totalProfit = max(ifSellProfit, ifNotSellProfit);
            dp[index][buy] = totalProfit;
        }
        return dp[index][buy];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int index = 0;
        int buy = 1;
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // buy=1 means you can buy and 0 means you cannot buy
        // as youb have previously bought before
        return profit(prices, index, buy, dp);
    }
};