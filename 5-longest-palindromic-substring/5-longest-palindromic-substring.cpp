class Solution {
public:
    pair<int,int> centerexpand(const string& s, int left, int right)
    {
        while(left>=0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return {left+1, right-1}
;    }
    string longestPalindrome(string s) 
    {
        int maxStart =0, maxEnd = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            auto [left1, right1] = centerexpand(s, i, i);
            auto [left2, right2] = centerexpand(s, i, i+1);
            
            if(right1-left1 > maxEnd-maxStart)
            {
                maxStart = left1;
                maxEnd = right1;
            }
            if(right2-left2 > maxEnd-maxStart)
            {
                maxStart = left2;
                maxEnd = right2;
            }
        }
        return s.substr(maxStart, maxEnd-maxStart+1);
    }
};