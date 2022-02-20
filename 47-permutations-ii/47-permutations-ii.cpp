class Solution {
private:
    vector<vector<int>>result;
    vector<int>path;
    void backtracking(vector<int>& nums, vector<bool>& used)
    {
        if(path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(i>0 && nums[i] == nums[i-1] && used[i-1] == true) continue;
            
            if(used[i] == false)
            {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        path.clear();
        result.clear();
        sort(nums.begin(), nums.end());
        vector<bool>used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};