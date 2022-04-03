class Solution {
public:
    string reverseWords(string s) 
    {
        stack<string>stk;
        string word;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] != ' '){
                word += s[i];
                if(i == s.size()-1 || s[i+1] == ' ')
                {
                    stk.push(word);
                    word = "";
                }
            }
        }
        string res;
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
            if(!stk.empty()) res += ' ';
        }
        return res;
    }
};