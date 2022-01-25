class Solution {
public:
    int calculate(string s) 
    {
        vector<int> stk;
        char preSign = '+';
        int num =0;
        for(int i=0; i<s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                num = num*10 + int (s[i]-'0');
            }
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.size()-1)
            {
                switch(preSign)
                {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    case '/':
                        stk.back() /= num;
                        break;
                }
                preSign =s[i];
                num =0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};