class Solution {
public:
    bool isValid(string& s, int left, int right)
    {
        for(int i=left, j=right; i<j; i++, j--)
        {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        int left=0, right=s.size()-1;
        
        while(left < right)
        {
            if(s[left] != s[right])
            {
                return isValid(s, left, right-1) || isValid(s, left+1, right);
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};