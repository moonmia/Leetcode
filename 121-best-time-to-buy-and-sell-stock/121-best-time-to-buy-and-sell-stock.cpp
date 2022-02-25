class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minPrice = INT_MAX;
        int maxProf = 0;
        for(int i=0; i<prices.size(); i++)
        {
            
            minPrice = min(prices[i], minPrice);
            maxProf = max(maxProf, prices[i]-minPrice);
            /*
            dp[i] = min(dp[i-1], prices[i]);
            maxProf = max(prices[i]- dp[i], maxProf);
            */
            
        }
        return maxProf;
    }
};