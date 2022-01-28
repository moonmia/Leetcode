class Solution {
public:
    string customSortString(string order, string s) 
    {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        
        for(int i=0; i<order.size(); i++)
        {
            cnt[order[i]-'a'] = i;
        }
        
        sort(s.begin(), s.end(), [&cnt](char a, char b)
        {
            return cnt[a-'a'] < cnt[b - 'a'];
        });
        return s;
    }
};