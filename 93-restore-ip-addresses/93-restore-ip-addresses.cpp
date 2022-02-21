class Solution {
private:
    vector<string>result;
    void backtracking(string& s, int startIndex, int pointNum)
    {
        if(pointNum == 3)
        {
            if(valid(s, startIndex, s.size()-1)) 
            {
                result.push_back(s);
            }
            return;
        }
        
        for(int i=startIndex; i<s.size(); i++)
        {
            if(valid(s, startIndex, i))
            {
                s.insert(s.begin()+i+1, '.');
                pointNum++;
                backtracking(s, i+2, pointNum);
                pointNum--;
                s.erase(s.begin()+i+1);
            }
            else break;
        }
        
    }
    bool valid(string& s, int left, int right)
    {
        if(left > right) return false;
        if(s[left] == '0' && left != right)
        {
            return false;
        }
        int num =0;
        for(int i=left; i<=right; i++)
        {
            if(s[i] > '9' || s[i] < '0') return false;
            
            num = num* 10 + (s[i] - '0');
            if(num >255) return false;
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) 
    {
        result.clear();
        if(s.size() > 12 ) return result;
        backtracking(s, 0, 0);
        return result;
        
    }
};