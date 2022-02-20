class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>>ans;
        map<string, vector<string>>mp;
        
        for(string& s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].emplace_back(s);
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};