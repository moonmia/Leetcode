class Solution {
private:
    vector<vector<int>>result;
    vector<int>path;
    
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex)
    {
        if(sum == target)
        {
            result.push_back(path);
            return;
        }
        for(int i=startIndex; i<candidates.size() && sum + candidates[i] <= target; i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};