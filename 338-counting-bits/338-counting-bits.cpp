class Solution {
public:
    int countOnes(int x)
    {
        int one =0;
        while(x)
        {
            x &= (x-1);
            one++;
        }
        return one;
    }
    vector<int> countBits(int n) 
    {
        vector<int>ans(n+1);
        for(int i=0; i<=n; i++)
        {
            ans[i] = countOnes(i);
        }
        return ans;
    }
};