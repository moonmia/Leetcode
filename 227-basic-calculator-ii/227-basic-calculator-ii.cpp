class Solution {
public:
    stack<int> num;
    stack<char> op; 

    void eval()
    {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char c= op.top(); op.pop();

        int result;
        if(c=='+') result=a+b;
        else if(c=='-') result=a-b;
        else if(c=='*') result=a*b;
        else result = a/b;
        num.push(result);
    }
    int calculate(string s) 
    {
        s = '0' + s; 
        unordered_map<char, int>pr;
        pr['+'] = pr['-'] =1, pr['*'] = pr['/'] =2; 
        for(int i=0; i<s.size(); i++)
        {
            char c = s[i];
            if(c == ' ') continue;
            if(isdigit(c))
            {
                int sum =0;
                while(i<s.size() && isdigit(s[i])) sum=sum*10 + (s[i++] - '0');
                i--;
                num.push(sum);
                
            }
            else
            {
                while(op.size() && pr[op.top()] >= pr[c]) eval();
                op.push(c);
            }
        }
        while(op.size()) eval();
        return num.top();
    }
};