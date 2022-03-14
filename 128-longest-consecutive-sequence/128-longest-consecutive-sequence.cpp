class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int>st;
        
        for(auto x : nums) st.insert(x);
        
        int res =0;
        for(auto x : st)
        {
            if(!st.count(x-1))
            {
                int y = x;
                while(st.count(y+1))
                {
                    y++; 
                }
                res = max(res, y-x+1);
            }
        }
        return res;
    }
};