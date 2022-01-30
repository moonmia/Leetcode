class Solution {
public:
    string simplifyPath(string path) 
    {
        vector<string>stk;
        int n= path.size();
        for(int i=0; i<n;)
        {
            if(path[i] == '/')
            {
                i++;
            }
            else
            {
                int cur = i;
                while (path[i] != '/' && i<n)
                {
                    i++;
                }
                string temp = path.substr(cur, i-cur);
                if(temp == ".." && !stk.empty())
                {
                    stk.pop_back();
                }
                else if(temp != ".." && temp != ".")
                {
                    stk.push_back(temp);
                }
               
            }
        }
        if(stk.empty()) return "/";
        string result;
        for(string &temp : stk)
        {
            result += "/" + temp;
        }
        return result;
    }
};