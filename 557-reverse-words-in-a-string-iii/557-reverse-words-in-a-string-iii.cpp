class Solution {
public:
    string reverseWords(string s) 
    {
        int left=0, right=0;
        
        while(right < s.size())
        {
            while(s[right] != ' ' && right <= s.size()-1)
            {
                right++;
            }
            
            int lleft=left, rright = right-1;
            
            while(lleft <= rright)
            {
                swap(s[lleft++], s[rright--]);
            }
            left = ++right;
        }
        return s;
    }
};