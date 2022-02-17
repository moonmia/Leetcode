class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>>ans;
        map<string, vector<string>>mp;
        
        for(auto s :strs)
        {
            string str = string(26, '0');
            for(auto c : s)
            {
                str[c-'a']++;
            }
            mp[str].emplace_back(s);
        }
        for(auto e : mp)
        {
            ans.emplace_back(e.second);
        }
        return ans;
    }
};