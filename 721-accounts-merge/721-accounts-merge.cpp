class Solution {
private:
    vector<int>f; 
    unordered_set<string> isAppread; 
    unordered_map<string, int> father; 
public:
    
    
    int find(int x)
    {
        return x == f[x] ? x : find(f[x]);
    }
    
    void merge(int x, int y)
    {
        int xFather = find(x);
        int yFather = find(y);

        if(xFather != yFather) f[yFather] = xFather;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        vector<vector<string>>res; 
       
        f = vector<int>(accounts.size());
        for(int i=0; i<f.size(); i++) f[i]=i;
       
        for(int i=0; i<accounts.size(); i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                
                if(!isAppread.count(accounts[i][j]))
                {
                    isAppread.insert(accounts[i][j]);
                    father[accounts[i][j]] = i;
                }
                else
                {
                    merge(father[accounts[i][j]], i);
                }
            }
        }
       
        unordered_map<int, set<string>> accMail;
        for(int i=0; i<accounts.size(); i++)
        {
            int t= find(i);
            int len = accounts[i].size();
            for(int j=1; j<len; j++) accMail[t].insert(accounts[i][j]);
        }
        
        for(auto acc : accMail)
        {
            vector<string> ans;
            ans.push_back(accounts[acc.first][0]);
            for(auto mail : acc.second) ans.push_back(mail);

            res.push_back(ans);
        }
        return res;
    }
};
