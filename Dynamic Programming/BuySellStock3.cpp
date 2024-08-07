// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
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
            // it mean you can buy now because you have not bought previously
            // now its up to you wether to buy or not
            // if buy then we canot buy again so mark buy as 0
            // if we buy then we are not completing the transaction so we will not chang e
            // cap that is the number of transacction left
            int ifBuyProfit = -prices[index] + profit(prices, index + 1, 0, dp, cap);
            int ifNotBuyProfit = 0 + profit(prices, index + 1, 1, dp, cap);
            totalProfit = max(ifBuyProfit, ifNotBuyProfit);
        }
        else
        {
            // you can sell because you have bought
            //  previously now its up to you wether to sell or not
            // if we sell then a transaction gets completed and reduce the cap value by 1
            int ifSellProfit = prices[index] + profit(prices, index + 1, 1, dp, cap - 1);
            int ifNotSellProfit = 0 + profit(prices, index + 1, 0, dp, cap);
            totalProfit = max(ifSellProfit, ifNotSellProfit);
        }
        return dp[index][buy][cap] = totalProfit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int index = 0;
        int buy = 1;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        // int cap=2 it means that we can complete two transactions
        return profit(prices, index, buy, dp, 2);
    }
};