class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int, int>freq, first, last;
        
        for(int i=0; i<nums.size(); i++)
        {
            freq[nums[i]] ++;
            if(first.count(nums[i]) == 0)
            {
                first[nums[i]] = i;
            }
            last[nums[i]]  = i;
        }
        int maxFreq = 0;
        for(auto it : freq)
        {
            maxFreq = max(maxFreq, it.second);
        }
        int res = nums.size();
        for(auto it : freq)
        {
            int num = it.first;
            int frequence = it.second;
            if(frequence == maxFreq)
            {
                int length = last[num] - first[num]+1;
                res = min(res, length);
            }
        }
        return res;
    }
};