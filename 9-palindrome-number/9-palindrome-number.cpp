class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x <0 || x%10==0 && x != 0) return false;
        
        string s = to_string(x);
        
        int left =0, right = s.size()-1;
        
        while (left <= right)
        {
            if(s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};