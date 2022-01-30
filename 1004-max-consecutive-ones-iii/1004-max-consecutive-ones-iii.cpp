class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int left =0, countZero =0;
        int ans=0;
        
        for(int right=0; right <nums.size(); right++)
        {
            if(nums[right] == 0)
            {
                countZero++;
            }
            
            while(countZero > k)
            {
                if(nums[left++] == 0)
                {
                    countZero--;
                }
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};