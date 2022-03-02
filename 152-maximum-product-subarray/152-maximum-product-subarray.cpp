class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        
        vector<int>dppos(nums), dpneg(nums);
        
        for(int i=1; i<nums.size(); i++)
        {
            dppos[i] = max(dppos[i-1]* nums[i], max(dpneg[i-1]*nums[i], nums[i]));
            dpneg[i] = min(dpneg[i-1]* nums[i], min(dppos[i-1]*nums[i], nums[i]));
        }
        return *max_element(dppos.begin(), dppos.end());
    }
};
/*
dp[i] = max(dp[i-1]*nums[i], nums[i]);

dppos[i] (positive) = max(dppos[i-1]*nums[i], dpneg[i-1]*nums[i], nums[i]);
dpneg[i] (negative) = min(dpneg[i-1]*nums[i], dpneg[i-1]*nums[i], nums[i]);
*/