class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0){
            return 0;
        }
        int di[4] = {0,0,1,-1};
        int dj[4] = {-1,1,0,0};
        grid[i][j] =0;
        int result=1;
        
        for(int index=0; index<4; index++){
            int newDi = i + di[index];
            int newDj = j + dj[index];
            result += dfs(grid, newDi, newDj);
        }
        return result;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    count = max(count, dfs(grid, i, j));
                }
            }
        }
        return count;
    }
};