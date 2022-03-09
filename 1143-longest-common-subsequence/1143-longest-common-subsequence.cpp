class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n1 = text1.size(), n2=text2.size();
        
        vector<vector<int>>dp(n1+1, vector<int>(n2+1));
        
        for(int i=1; i<=n1; i++)
        {
            char c1 = text1.at(i-1);
           
            for(int j = 1; j<=n2; j++)
            {
                char c2 = text2.at(j-1);
                if(c1==c2)
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n1][n2];
        
    }
};
/*
dp[i] = the length of the longest common subsequence

dp[0] = 0;
dp[1] = 1;
dp[i] = (dp[j]+1, dp[i])
*/