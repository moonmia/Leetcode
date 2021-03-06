class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        /*
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        
        for(int i=1; i<n; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
        }
        return dp[n-1][0];
        */
        int n = prices.size();
        int dp0 = 0, dp1 = -prices[0];
        
        for(int i=1; i<n; i++)
        {
            int newDp0 = max(dp0, dp1 + prices[i]);
            int newDp1 = max(dp0-prices[i], dp1);
            dp0 = newDp0;
            dp1 = newDp1;
        }
        return dp0;
    }
};

/*
dp[i][0] = max (dp[i-1][0]  dp[i-1][1] + prices[i]);
dp[i][1] = max (dp[i-1][0] - prices[i], dp[i-1][1]);
*/