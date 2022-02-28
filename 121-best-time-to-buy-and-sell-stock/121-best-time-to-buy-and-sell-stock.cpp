class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxp = INT_MIN;
        int minprice = INT_MAX;
        for(int i=0; i<prices.size(); i++)
        {
            minprice = min(prices[i], minprice);
            maxp = max(prices[i]-minprice, maxp);
        }
        return maxp;
    }
};