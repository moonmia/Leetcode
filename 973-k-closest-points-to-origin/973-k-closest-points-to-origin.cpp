class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int, int>>que;
        
        for(int i=0; i<k; i++)
        {
            que.emplace(points[i][0]*points[i][0] + points[i][1]*points[i][1], i);
        }
        
        for(int i=k; i<points.size(); i++)
        {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            
            if(dist <= que.top().first)
            {
                que.pop();
                que.emplace(dist, i);
            }
            
        }
        vector<vector<int>>result;
        while(!que.empty())
        {
            result.push_back(points[que.top().second]);
            que.pop();
        }
        return result;
        
    }
};