class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1) return nums[0];
        vector<int>dp(nums.size()+1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};
/*
dp[0] = nums[0];
dp[1] = max(nums[0], nums[1]);
dp[2] = max(dp[1], nums[1]) = max(1, 2) = 2
dp[3] = max(dp[1]+nums[2], dp[2]) = max(1+3,2) =4
dp[4] = max(dp[3], dp[2]+nums[3]) = (4, 3) = 4
dp[i] = max(dp[i-1], dp[i-2]+nums[i-1])
*/
