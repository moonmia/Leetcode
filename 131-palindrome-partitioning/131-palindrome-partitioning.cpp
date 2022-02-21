class Solution {
private:
    vector<vector<string>>result;
    vector<string>path;
    void backtracking(string& s, int startIndex)
    {
        if(startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }
        
        for(int i=startIndex; i<s.size(); i++)
        {
            if(isPalindrome(s, startIndex, i))
            {
                string sub = s.substr(startIndex, i-startIndex+1);
                path.push_back(sub);
            }
            else
            {
                continue;
            }
            backtracking(s, i+1);
            path.pop_back();
        }
    }
    
    bool isPalindrome(string& s, int left, int right)
    {
        for(int i=left, j=right; i<j; i++, j--)
        {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) 
    {
        path.clear();
        result.clear();
        backtracking(s, 0);
        return result;
    }
};