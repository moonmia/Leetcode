class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int minSum = INT_MAX;
        int sum, ans;
        
        for(int i=0; i<n; i++)
        {
            int left = i+1, right = n-1;
            while (right > left)
            {
                sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < minSum)
                {
                    minSum = abs(sum-target);
                    ans = sum;
                }
                if(sum > target)
                {
                    right--;
                    
                }
                else if(sum < target)
                {
                    left ++;
                }
                else
                {
                    return sum;
                }
                
            }
        }
        return ans;
    }
};