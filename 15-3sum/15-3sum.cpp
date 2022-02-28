class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<int>>result;
        
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0) return result;
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = n-1;
            
            while(right > left)
            {
                if(nums[i] + nums[left] + nums[right] > 0) right --;
                else if(nums[i] + nums[left] + nums[right] <0) left++;
                else 
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(right > left && nums[right] ==  nums[right-1]) right--;
                    while(right > left && nums[left] == nums[left+1]) left++;
                    
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};