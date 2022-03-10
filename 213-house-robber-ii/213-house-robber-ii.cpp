class Solution {
public:
    
    int situation(vector<int>& nums, int left, int right)
    {
        vector<int> dp(nums.size()+1);
        //int first = nums[left];
        //int second = max(nums[left], nums[left+1]);
        dp[left] = nums[left], dp[left+1] = max(nums[left], nums[left+1]);
        
        for(int i=left+2; i<=right; i++)
        {
            //int temp = second;
            //second = max(first+nums[i], second);
            //first = temp;
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[right];
    }
    
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1) return nums[0];
        else if(n==2) return max(nums[0], nums[1]);
        return max(situation(nums, 0, n-2), situation(nums, 1, n-1));
        
    }
    
};
/*
(0, n-2) || (1, n-1)
dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
*/