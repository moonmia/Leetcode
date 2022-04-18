class Solution {
public:
    string decodeString(string s) {
        stack<int>nums;
        stack<string>character;
        string res = "";
        int n = s.size();
        int num=0;
        
        for(int i=0; i<n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                num = num *10 + s[i] - '0';
            }
            else if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
                res += s[i];
            }
            else if(s[i] == '['){
                nums.push(num);
                num = 0;
                character.push(res);
                res = "";
            }
            else{
                int t = nums.top();
                nums.pop();
                for(int j=0; j<t; j++){
                    character.top() += res;
                }
                res = character.top();
                character.pop();
            }
        }
        return res;
    }
};