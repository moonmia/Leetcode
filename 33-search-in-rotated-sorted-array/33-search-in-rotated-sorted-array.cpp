class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        if(n == 0) return -1;
        if(n ==1)
        {
            if(nums[0] == target) return 0;
            else return -1;
        }
        int left=0, right = n-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            if(nums[0] <= nums[mid])
            {
                if(target >= nums[0] && target < nums[mid])
                {
                    right = mid-1;
                }
                else
                {
                    left = mid+1;
                }
            }
            else
            {
                if(target > nums[mid] && target <= nums[n-1])
                {
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};