class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        stack<char>stk;
        
        for(int i=0; i<s.size(); i++)
        {
            if(!stk.empty())
            {
                if(s[i] == ')' && stk.top() == '(')
                {
                    stk.pop();
                }
                else
                {
                    stk.push(s[i]);
                }
            }
            else
            {
                stk.push(s[i]);
            }
                
        }
        return stk.size();
    }
};