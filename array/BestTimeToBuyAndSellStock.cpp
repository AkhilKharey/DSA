class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // minimum buying price assume to be first element
        int minimum=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            int tempProfit=prices[i]-minimum;
            profit=max(profit,tempProfit);
            // buying price should be minimum value before sell
            minimum=min(minimum,prices[i]);
        }
        return profit;  
    }
};