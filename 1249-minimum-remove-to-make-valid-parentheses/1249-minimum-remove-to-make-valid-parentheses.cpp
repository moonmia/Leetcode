class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int>stk;
        vector<int>deleteIndex;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
            {
                stk.push(i);
            }
            if(s[i] == ')')
            {
                if(stk.empty())
                {
                    deleteIndex.push_back(i);
                }
                else
                {
                    stk.pop();
                }
            }
        }
        int temp = deleteIndex.size();
        while(!stk.empty())
        {
            deleteIndex.push_back(stk.top());
            stk.pop();
        }
        reverse(deleteIndex.begin()+temp, deleteIndex.end());
        
        auto size = s.begin();
        for(auto it = deleteIndex.rbegin(); it != deleteIndex.rend(); it++)
        {
            s.erase(size + *it);
        }
        return s;
    }
};