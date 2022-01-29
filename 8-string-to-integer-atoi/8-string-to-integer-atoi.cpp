class Solution {
public:
    int myAtoi(string s) 
    {
        unsigned long len = s.length();
        int i=0;
        
        while(i < len)
        {
            if(s[i] != ' ') break;
            i++;
        }
        
        if(i == len) return 0;
        int sign =1;
        if(s[i] == '+') i++;
        else if(s[i] == '-')
        {
            sign = -1;
            i++;
        }
        
        int result=0;
        while(i < len)
        {
            char cur = s[i];
            if(s[i] < '0' || s[i] > '9') break;
            if(result > INT_MAX/10 || (result == INT_MAX/10 && (cur - '0') > INT_MAX%10)) return INT_MAX;
            if(result < INT_MIN/10 || (result == INT_MIN/10 && (cur - '0') > -(INT_MIN%10))) return INT_MIN;
            result = result*10 + sign*(cur - '0');
            i++;
        }
        return result;
    }
};