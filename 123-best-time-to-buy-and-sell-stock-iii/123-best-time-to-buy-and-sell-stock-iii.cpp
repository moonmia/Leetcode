class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int buy1 = -prices[0];
        int sell1 = 0;
        int buy2 = -prices[0];
        int sell2 =0;
        
        for(int i=1; i<n; i++)
        {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, prices[i]+buy1);
            buy2 = max(buy2, sell1-prices[i]);
            sell2 = max(sell2, prices[i]+buy2);
        }
        return sell2;
    }
};
/*
1. no operation
2. only once
3. 
*/