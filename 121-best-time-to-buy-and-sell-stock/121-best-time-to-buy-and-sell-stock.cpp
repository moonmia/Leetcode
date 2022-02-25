class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        vector<int>dp(prices.size());
        dp[0] = prices[0];
        int maxProf = 0;
        for(int i=1; i<prices.size(); i++)
        {
            dp[i] = min(dp[i-1], prices[i]);
            maxProf = max(prices[i]- dp[i], maxProf);
            
        }
        return maxProf;
    }
};