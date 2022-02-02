class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.size() == 0) return "";
        
        string str = strs[0];
        
        for(int i=1; i<strs.size(); i++)
        {
            string s = str;
            str = "";
            
            for(int j=0; j<strs[i].size(); j++)
            {
                if(s[j] == strs[i][j])
                {
                    str += s[j];
                }
                else
                {
                    break;
                }
            }
            if (str == "") break;
        }
        return str;
    }
};