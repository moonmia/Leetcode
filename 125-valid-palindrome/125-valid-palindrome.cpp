class Solution {
public:
    bool isPalindrome(string s) 
    {
        string temp;
        
        for(char ch : s)
        {
            if(isalnum(ch))
            {
                temp += tolower(ch);
            }
        }
        string temp_reversed(temp.rbegin(), temp.rend());
        return temp == temp_reversed;
    }
};