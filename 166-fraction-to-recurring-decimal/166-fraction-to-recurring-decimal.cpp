class Solution {
    using ll = long long;
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        ll n = numerator, d = denominator;
        string ret;
        if(n*d < 0) ret += '-';
        
        ll a = n / d;
        if(a < 0 ) a *= -1;
        ret += to_string(a);
        
        if(n < 0) n *= -1;
        if(d < 0) d *= -1;
        
        n %= d;
        
        if(n == 0) return ret;
        ret += '.';
        unordered_map<int,int>mp;
        string temp;
        int i=0;
        while (n && !mp.count(n))
        {
            mp[n] = i++;
            n *= 10;
            temp.push_back((char)(n/d + '0'));
            n %= d;
        }
        if(n != 0)
        {
            ret += temp.substr(0, mp[n]) + "(" + temp.substr(mp[n]) + ")";
        }
        else
        {
            ret += temp;
        }
        return ret;
    }
};