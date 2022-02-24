class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        unordered_map<int, int>mp;
        int count =0;
        for(const auto& i : nums)
        {
            mp[i]++;
        }
        
        for(const auto& m : mp)
        {
            if(k ==0) count += (m.second>1);
            else count += mp.count(m.first-k);
        }
        return count;
    }
};