class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (i >= rows || i < 0 || j >= cols || j < 0) return;
        if (grid[i][j] == '0') return;          //  如果遍历到海水，则返回
        grid[i][j] = '0';                       //  将陆地变成海水, 每次遍历到一个岛屿，就会将其淹没
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {        //  找到一块属于某个岛屿的陆地，将岛屿数量加一并将其淹没
                    res++;
                    dfs(grid, i, j);            
                }
            }
        }
        return res;
    }
};