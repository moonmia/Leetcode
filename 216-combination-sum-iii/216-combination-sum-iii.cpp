class Solution {
private:
    vector<vector<int>>result;
    vector<int>path;
    void backtracking(int k, int n, int startIndex, int sum)
    {
        if(sum == n && path.size() == k)
        {
            result.push_back(path);
            return;
        }
        
        for(int i=startIndex; i<=9 && sum + i <= n && path.size() <= k; i++)
        {
            sum += i;
            path.push_back(i);
            backtracking(k, n, i+1, sum);
            sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        path.clear();
        result.clear();
        backtracking(k, n, 1, 0);
        return result;
        
    }
};