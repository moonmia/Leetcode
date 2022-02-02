class Solution {
public:
    vector<int>num;
    Solution(vector<int>& nums) 
    {
        num = nums;
    }
    
    int pick(int target) 
    {
        int ans=-1, n=0;
        
        for(int i=0; i<num.size(); i++)
        {
            if(num[i] == target)
            {
                n++;
                if(rand()% n ==0) ans =i; 
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */