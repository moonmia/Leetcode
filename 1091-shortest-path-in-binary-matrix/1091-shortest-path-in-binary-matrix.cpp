class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if(grid[0][0] == 1) return -1;
        int n= grid.size(), ans=1;
        
        const int direction[8][2] = { {1,0}, {-1,0}, {0,1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1,-1}};
        
        queue<pair<int, int>>que;
        
        que.emplace(0,0);
        grid[0][0] =1;
        while(!que.empty())
        {
            int m=que.size();
            while(m--)
            {
                auto [x,y] = que.front();
                que.pop();
                
                if(x==n-1 && y ==n-1) return ans;
                
                for(int i=0; i<8; i++)
                {
                    int nx=x+direction[i][0];
                    int ny=y+direction[i][1];
                    if(nx<0 || ny<0||nx>=n||ny>=n) continue;
                    if(grid[nx][ny] ==0)
                    {
                        que.emplace(nx,ny);
                        grid[nx][ny] =1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};