class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int s = strs.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1, 0));
        
        for(string s : strs)
        {
            int numZero = 0, numOne=0;
            
            for(char c : s)
            {
                if(c == '0') numZero++;
                else numOne++;
            }
            
            for(int i=m; i>= numZero; i--)
            {
                for(int j=n; j>=numOne; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i-numZero][j-numOne]+1);
                }
            }
        }
        return dp[m][n];
    }
};