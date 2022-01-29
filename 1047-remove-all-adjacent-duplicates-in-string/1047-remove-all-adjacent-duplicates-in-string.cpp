class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char>stk;
        for(char ch : s)
        {
            if(!stk.empty() && ch == stk.top())
            {
                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }
        string result;
        while(!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};