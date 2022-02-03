class Solution {
public:
    int countSubstrings(string s) 
    {
        int num=0, n=s.size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=1; j++)
            {
                int l=i;
                int r=i+j;
                while(l>=0 && r<n &&s[l--] == s[r++]) num++;
            }
        }
        return num;
    }
};