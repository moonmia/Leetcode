class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n = nums.size();
        if(n == 0) return {-1,-1};
        int left =0, right = nums.size()-1;
        
        while(left < right)
        {
            int mid = left + (right-left) /2;
            
            if(target <= nums[mid])
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        if(nums[right] != target) return {-1,-1};
        int firstPos = right;
        left =0, right = nums.size()-1;
        while(left < right)
        {
            int mid = left + (right-left +1) /2;
            
            if(target < nums[mid])
            {
                right = mid-1;
            }
            else
            {
                left = mid;
            }
            
        }
        return {firstPos, right};
    }
};