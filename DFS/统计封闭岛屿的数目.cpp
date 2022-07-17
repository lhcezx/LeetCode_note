class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int row = grid.size();
        int col = grid[0].size();
        if (i >= row || i < 0 || j >= col || j < 0) return;
        if (grid[i][j] == 1) return;
        grid[i][j] = 1;                 //  将岛屿淹没
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {                    //  淹没第一列和最后一列的边界岛屿
            dfs(grid, i, 0);
            dfs(grid, i, cols - 1);
        }
        for (int j = 1; j < cols - 1; j++) {                //  淹没第一行和最后一行的边界岛屿
            dfs(grid, 0, j);
            dfs(grid, rows - 1, j);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) res++;
                dfs(grid, i, j);
            }
        }
        return res;
    }
};