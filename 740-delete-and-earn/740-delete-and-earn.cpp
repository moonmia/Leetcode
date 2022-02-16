class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        int size = nums.size(), maxn = 0;
        vector<int>a (10001, 0);
        
        for(auto& x : nums)
        {
            a[x] += x;
            maxn = max(maxn, x);
        }
        
        vector<int>dp(maxn+1, 0);
        dp[1] = a[1];
        for(int i=2; i<=maxn; i++)
        {
            dp[i] = max(dp[i-2]+a[i], dp[i-1]);
        }
        return dp[maxn];
    }
};