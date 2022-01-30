class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int left=0, right=nums.size()-1, pos= nums.size()-1;
        vector<int>ans(nums.size());
        while(left<=right)
        {
            if(nums[left]*nums[left] > nums[right]*nums[right])
            {
                ans[pos] = nums[left]*nums[left];
                left++;
            }
            else
            {
                ans[pos] = nums[right]*nums[right];
                right--;
            }
            pos--;
        }
        return ans;
    }
};