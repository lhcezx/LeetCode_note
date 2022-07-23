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
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res = 0;
        int rows = grid2.size();
        int cols = grid2[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid2[i][j] == 1 && grid1[i][j] != 1) dfs(grid2, i, j);     //  grid2的陆地如果在grid1不是陆地，那么这个岛屿必不是子岛，将其淹没
            }
        }

        for (int i = 0; i < rows; i++) {                                        //  剩下的岛屿都是子岛屿，统计数量即可
            for (int j = 0; j < cols; j++) {
                if (grid2[i][j] == 1) {
                    res++;
                    dfs(grid2, i, j);
                }
            }
        }
        return res;
    }
};