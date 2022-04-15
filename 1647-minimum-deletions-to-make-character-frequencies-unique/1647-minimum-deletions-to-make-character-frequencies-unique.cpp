class Solution {
public:
    int minDeletions(string s) 
    {
        vector<int>cnt(26,0);
        for(char ch : s){
            cnt[ch - 'a']++;
        }
        
        sort(cnt.begin(), cnt.end(), greater<int>());
        
        int prev = cnt[0];
        int ans=0;
        for(int i=1; i<26 && cnt[i] >0; i++){
            if(prev > cnt[i]){
                prev = cnt[i];
            }
            else{
                prev = max(prev-1, 0);
                ans += (cnt[i] - prev);
            }
        }
        return ans;
    }
};