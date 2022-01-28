class Solution {
public:
    int maximumSwap(int num) 
    {
        string s = to_string(num);
        vector<int>index(10,0);
        
        for(int i=0; i<s.size(); i++)
        {
            index[s[i] - '0'] = i;
        }
        
        for(int i=0; i<s.size(); i++)
        {
            for(int digit=9; digit > s[i]-'0'; digit--)
            {
                if(index[digit] > i)
                {
                    swap(s[index[digit]], s[i]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};