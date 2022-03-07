class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        unordered_set<int>st;
        
        for(int i=0; i<nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        int missing =-1;
        for(int i=0; i<=nums.size(); i++)
        {
            if(!st.count(i))
            {
                missing = i;
                break;
            }
        }
        return missing;
    }
};