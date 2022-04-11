class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i <0 || j<0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] ==1){
            return;
        }
        int di[4] = {1,-1, 0, 0};
        int dj[4] = {0,0,-1,1};
        grid[i][j] = 1;
        
        for(int index=0; index<4; index++){
            int newDi = i +di[index];
            int newDj = j +dj[index];
            dfs(grid, newDi, newDj);
        }
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
        int count=0;
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
                if(grid[i][j] == 0)
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};