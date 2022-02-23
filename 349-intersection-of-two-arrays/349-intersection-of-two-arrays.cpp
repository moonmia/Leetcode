class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> result;
        unordered_set<int>numset(nums1.begin(), nums1.end());
        
        for(int i=0; i<nums2.size(); i++)
        {
            if(numset.find(nums2[i]) != numset.end())
            {
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};