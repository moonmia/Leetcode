class compare{
public:
    bool operator()(const pair<int,int>& a, const pair<int, int>& b)
    {
        return a.second >b.second;
    }
    
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int>map;
        
        for(int i=0; i<nums.size(); i++)
        {
            map[nums[i]]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;
        
        for(unordered_map<int, int>:: iterator it = map.begin(); it != map.end(); it++)
        {
            que.push(*it);
            
            if(que.size() >k)
            {
                que.pop();
            }
        }
        
        vector<int>result(k);
        for(int i=que.size()-1; i>=0; i--)
        {
            result[i] = que.top().first;
            que.pop();
        }
        return result;
    }
};