class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        int left =0, right=1;
        
        while(right < n)
        {
            if(nums[right] != nums[right-1])
            {
                nums[left+1] = nums[right];
                left++;
            }
            right++;
        }
        return left+1;
    }
};