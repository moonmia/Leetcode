class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int preSum=0, maxSum = nums[0];
        
        for(const int& n : nums)
        {
            preSum = max(preSum+n, n);
            maxSum = max(maxSum, preSum);
        }
        return maxSum;
    }
};