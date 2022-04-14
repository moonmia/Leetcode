class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = INT_MAX /2;
        
        vector<vector<int>> graph(n, vector<int>(n, inf));
        for(auto& time : times){
            int x = time[0]-1;
            int y = time[1]-1;
            graph[x][y] = time[2];
        }
        
        vector<int>dist(n, inf);
        dist[k-1] =0;
        
        vector<bool> used(n);
        
        for(int i=0; i<n; i++){
            int x = -1;
            for(int y=0; y<n; y++){
                if(!used[y] && (x==-1 || dist[y] < dist[x])){
                    x =y;
                }
            }
            used[x] = true;
            for(int y=0; y<n; y++){
                dist[y] = min(dist[y], dist[x] + graph[x][y]);
            }
        
        
        }
        
        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};