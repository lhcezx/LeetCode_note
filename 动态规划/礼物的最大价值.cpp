class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (i == 0 && j == 0){
                    continue;
                } else if (i == 0 && j != 0) {
                    grid[0][j] = grid[0][j-1] + grid[0][j];
                } else if (i != 0 && j == 0) {
                    grid[i][0] = grid[i-1][0] + grid[i][0];
                } else {
                    grid[i][j] = grid[i][j] + max(grid[i-1][j], grid[i][j-1]);
                }
            }
        }
        return grid.back().back();;
    }
};