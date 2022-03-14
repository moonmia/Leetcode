class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        unordered_map<string, int>mp;
        vector<string>ans;
        
        for(int i=0; i<=int(s.size())-10; i++)
        {
            string a = s.substr(i,10);
            mp[a]++;
        }
        
        for(auto &it : mp)
        {
            if(it.second >= 2)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};