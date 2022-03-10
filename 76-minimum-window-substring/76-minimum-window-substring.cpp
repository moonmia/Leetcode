class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int>hs;
        unordered_map<char,int>ht;
        
        for(char a : t)
        {
            ht[a]++;
        }
        
        string res;
        int count =0;
        
        for(int i=0, j=0; i<s.size(); i++)
        {
            hs[s[i]]++;
            
            if(hs[s[i]] <= ht[s[i]]) count++;
            
            while(hs[s[j]] > ht[s[j]]) hs[s[j++]]--;
            if(count == t.size())
            {
                if(res.empty() || i-j+1 < res.size())
                {
                    res = s.substr(j, i-j+1);
                }
            }
        }
        return res;
    }
};