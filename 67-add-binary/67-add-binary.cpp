class Solution {
public:
    string addBinary(string a, string b) 
    {
        int aSize = a.size();
        int bSize = b.size();
        
        while(aSize < bSize)
        {
            a = '0' +a;
            aSize ++;
        }
        while(aSize > bSize)
        {
            b = '0' +b;
            bSize++;
        }
        
        for(int i= aSize-1; i>0; i--)
        {
            a[i] = a[i]-'0' + b[i];
            if(a[i] >= '2')
            {
                a[i] = (a[i]-'0') % 2 + '0';
                a[i-1] = a[i-1] +1;
            }
        }
        a[0] = a[0] - '0' + b[0];
        if(a[0] >= '2')
        {
            a[0] = (a[0] - '0')%2 + '0';
            a = '1' +a;
        }
        return a;
    }
};