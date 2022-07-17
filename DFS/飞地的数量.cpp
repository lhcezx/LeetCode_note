class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (i >= rows || i < 0 || j >= cols || j < 0) return;
        if (grid[i][j] == 0) return;
        grid[i][j] = 0;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {        //  将所有边界岛屿变为海洋单元格
            dfs(grid, i, 0);
            dfs(grid, i, cols - 1);
        }
        for (int j = 1; j < cols - 1; j++) {
            dfs(grid, 0, j);
            dfs(grid, rows - 1, j);
        }

        for (int i = 0; i < rows; i++) {        //  统计剩余陆地的数量
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) res++;
            }
        }
        return res;
    }
};