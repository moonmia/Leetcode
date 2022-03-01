class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        
        if(prices.empty()) return 0;
        int n = prices.size();
        k = min(k, n/2);
        vector<vector<int>>one(n, vector<int>(k+1));
        vector<vector<int>>zero(n, vector<int>(k+1));
        
        for(int i=1; i<=k; i++)
        {
            one[0][i] = zero[0][i] = INT_MIN /2;
        }
        
        one[0][0] = -prices[0];
        for(int i=1; i<n; i++)
        {
            one[i][0] = max(one[i-1][0], zero[i-1][0] - prices[i]);
            for(int j=1; j<=k; j++)
            {
                one[i][j] = max(one[i-1][j], zero[i-1][j] -prices[i]);
                zero[i][j] = max(zero[i-1][j], one[i-1][j-1]+prices[i]);
            }
        }
        return *max_element(zero[n-1].begin(), zero[n-1].end());
        
    }
};

/*
zero[i][j] -- in (0, i)th day, has j time of transactions, and no stock in hand
one[i][j] -- in (0, i)th day, has j time of transactions, and one stock in hand

one[i][j] = max(one[i-1][j], zero[i-1][j]- prices[i]);
zero[i][j] = max(zero[i-1][j], one[i-1][j] + prices[i]);

one[0][j] = -prices[0];
zero[0][j] = 0;

*/