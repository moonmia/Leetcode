class Solution {
public:
    unordered_set<string> unique;
    
    
    vector<string> removeInvalidParentheses(string s) 
    {
        int l=0, r=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
            {
                l++;
            }
            else if(s[i] == ')')
            {
                if(l==0)
                {
                    r++;
                }
                else
                {
                    l--;
                }
            }
        }
        string temp = "";
        dfs(s, temp, 0, l,0, r, 0);
        
        vector<string>result;
        for(auto s : unique)
        {
            result.push_back(s);
        }
        
        return result;
    }
    
    void dfs(string& s, string& temp, int i, int l, int lcnt, int r, int rcnt)
    {
        if(i == s.size())
        {
            if(l==0 & r==0) unique.insert(temp);
            return;
        }
        
        if(s[i] == '(' && l>0)
        {
            dfs(s, temp, i+1, l-1, lcnt, r, rcnt);
        }
        
        if(s[i] == ')' && r >0)
        {
            dfs(s, temp, i+1, l, lcnt, r-1, rcnt);
        }
        
        temp.push_back(s[i]);
        if(s[i] != '(' && s[i] != ')')
        {
            dfs(s, temp, i+1, l, lcnt, r, rcnt);
        }
        else if(s[i] == '(')
        {
            dfs(s, temp, i+1, l, lcnt+1, r, rcnt);
        }
        else if(rcnt < lcnt)
        {
            dfs(s, temp, i+1, l, lcnt, r, rcnt+1);
        }
        temp.pop_back();
    }
};