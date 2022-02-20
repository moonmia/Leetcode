class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int n1=num1.size(), n2=num2.size();
        vector<int>a,b;
        for(int i=n1-1; i>=0; i--) a.push_back(num1[i]-'0');
        for(int i=n2-1; i>=0; i--) b.push_back(num2[i]-'0');
        
        vector<int>c(n1+n2);
        
        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<n2; j++)
            {
                c[i+j] += a[i] * b[j];
            }
        }
        int temp = 0;
        for(int i=0; i<c.size(); i++)
        {
            temp += c[i];
            c[i] = temp % 10;
            temp /= 10;
        }
        
        int k= c.size()-1;
        while(k >0 && !c[k]) k--;
        string result;
        while (k >= 0) result += c[k--] + '0';
        return result;
    }
};