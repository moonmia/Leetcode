class Solution {
public:
    vector<string>res;
    vector<string> generateParenthesis(int n) 
    {
        dfs(n,0,0, "");
        return res;
    }
    
    void dfs(int n, int lc, int rc, string str)
    {
        if(lc == n && rc == n)
        {
            res.push_back(str);
        }
        else
        {
            if(lc < n) dfs(n, lc+1, rc, str+ "(");
            if(rc < n && rc < lc) dfs(n, lc, rc+1, str+")");
        }
    }
};