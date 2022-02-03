class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int left=0, right = count(begin(s), end(s), ')');
        string ans = "";
        
        for(auto& c : s)
        {
            if(c == '(')
            {
                if(right)
                {
                    ans += c;
                    right--; 
                    left++;
                }
            }
            else if(c==')')
            {
                if(left)
                {
                    ans += c;
                    left--;
                }
                else
                {
                    right--;
                }
            }
            else
            {
                ans += c;
            }
        }
        return ans;
    }
};