class Solution {
public:
    bool isValid(string s) 
    {
        unordered_map<char,char>mp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        stack<char>stk;
        
        for(char ch : s)
        {
            if(mp.count(ch))
            {
                if(stk.empty() || stk.top() != mp[ch])
                {
                    return false;
                }
                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};