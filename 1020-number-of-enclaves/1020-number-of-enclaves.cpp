class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || x >= grid.size() || y <0 || y >=grid[0].size() || grid[x][y] == 0){
            return;
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        grid[x][y] = 0;
        
        for(int i=0; i<4; i++){
            int newDx = x + dx[i];
            int newDy = y + dy[i];
            dfs(grid, newDx, newDy);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int count =0;
        for(int i=0; i<grid.size(); i++){
            dfs(grid, i, 0);
            dfs(grid, i, grid[0].size()-1);
        }
        for(int j=0; j<grid[0].size(); j++){
            dfs(grid, 0, j);
            dfs(grid, grid.size()-1, j);
        }
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    count++;
                }
                
                
            }
        }
        return count;
    }
};