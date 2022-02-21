class Solution {
public:
    bool hasNum, hasE, hasDot;
    bool isNumber(string s) 
    {
        for(int i=0; i<s.size(); i++)
        {
            auto c = s[i];
            if((c == '+' || c == '-') && (i==0 || s[i-1] == 'e' || s[i-1] == 'E'))
            {
                continue;
            }
            else if(c == '.' && !hasDot && !hasE)
            {
                hasDot = true;
            }
            else if((c == 'e' || c == 'E') && !hasE && hasNum)
            {
                hasE = true;
                hasNum = false;
            }
            else if(isdigit(c))
            {
                hasNum = true;
            }
            else
            {
                return false;
            }
        }
        return hasNum;
    }
};