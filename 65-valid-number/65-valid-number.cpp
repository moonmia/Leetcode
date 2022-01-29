class Solution {
public:
    bool hasE, hasNum, isFloat;
    bool isNumber(string& s) 
    {
        for(int i=0; i<s.size(); i++)
        {
            auto c=s[i];
            if((c == '-' || c=='+') && (i==0 || s[i-1] == 'e' || s[i-1] == 'E'))
            {
                
            }
            else if((c=='e' || c=='E') && !hasE && hasNum)
            {
                hasE=true;
                hasNum = false;
            }
            else if(c=='.' && !isFloat && !hasE)
            {
                isFloat = true;
            }
            else if(isdigit(c))
            {
                hasNum=true;
            }
            else
            {
                return false;
            }
        }
        return hasNum;
    }
};