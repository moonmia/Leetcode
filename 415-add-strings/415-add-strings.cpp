class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        if(num2.size() == 0) return num1;
        
        int m =num1.size()-1, n = num2.size()-1, add=0;
        
        string result = "";
        
        while(m>=0 || n >=0 || add != 0)
        {
            int x = m >=0 ? num1[m] - '0' : 0;
            int y = n >=0 ? num2[n] - '0' : 0;
            
            int sum = x+y+add;
            result.push_back('0' + sum%10);
            add = sum/10;
            m--;
            n--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};