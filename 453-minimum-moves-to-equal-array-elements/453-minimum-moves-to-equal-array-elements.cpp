class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        int minNum = *min_element(nums.begin(), nums.end());
        int result=0;
        for(int num : nums)
        {
            result += num - minNum;
        }
        return result;
    }
};