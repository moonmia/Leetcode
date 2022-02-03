class Solution {
public:
    vector<int> diffWaysToCompute(string expression) 
    {
        vector<int>res;
        
        for(int i=0; i<expression.size(); i++)
        {
            char c=expression[i];
            if(c == '+' || c == '-' || c == '*')
            {
                vector<int>left = diffWaysToCompute(expression.substr(0,i));
                vector<int>right = diffWaysToCompute(expression.substr(i+1,expression.size()));
                for(int& l : left)
                {
                    for(int& r : right)
                    {
                        if(c == '+')
                        {
                            res.push_back(l+r);
                        }
                        else if(c == '-')
                        {
                            res.push_back(l-r);
                        }
                        else
                        {
                            res.push_back(l*r);
                        }
                    }
                }
            }
        }
        if(res.size()==0) res.push_back(stoi(expression));
        return res;
    }
};