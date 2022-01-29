class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>map = {{0,-1}};
        int reminder = 0;
        for(int i=0; i<nums.size(); i++)
        {
            reminder = (reminder + nums[i])%k;
            
            if(map.count(reminder))
            {
                int position = map[reminder];
                
                if((i-position) >=2)
                {
                    return true;
                }
            }
            else
            {
                map[reminder] = i;
            }
        }
        return false;
    }
};