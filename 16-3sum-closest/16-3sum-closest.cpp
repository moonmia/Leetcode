class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        //[-4,-1,1,2]
        int n = nums.size();
        int sum, smallest = INT_MAX, ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++)
        {
            for(int left =i+1, right =n-1; left <right;)
            {
                sum = nums[i]+nums[left]+nums[right];
                
                if(abs(sum-target) < smallest)
                {
                    smallest = abs(sum-target);
                    ans = sum;
                }
                
                if(sum == target) return sum;
                
                else if(sum < target) left++;
                
                else right--;
            }
        }
        return ans;
    }
};