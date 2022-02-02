class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        int row_size = grid.size();
        int col_size = grid[0].size();
        if(x <0 || x == row_size || y <0 || y == col_size || grid[x][y] == '0') return;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        grid[x][y] = '0';
        
        for(int k=0; k<4; k++)
        {
            int new_x = x + dx[k];
            int new_y = y + dy[k];
            dfs(grid, new_x, new_y);
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int result=0;
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }
};