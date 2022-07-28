class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 && j == 0) continue;
                int up = i - 1 >= 0 ? dp[i - 1][j] : INT_MAX / 2;
                int left = j - 1 >= 0 ? dp[i][j - 1]: INT_MAX / 2;
                dp[i][j] = min(up, left) + grid[i][j];
            }
        }
        return dp[rows - 1][cols - 1];
    }
};


//  空间优化版


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> dp(cols);
        dp[0] = grid[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 && j == 0) continue;
                int up = i - 1 >= 0 ? dp[j] : INT_MAX / 2;
                int left = j - 1 >= 0 ? dp[j - 1]: INT_MAX / 2;
                dp[j] = min(up, left) + grid[i][j];
            }
        }
        return dp[cols - 1];
    }
};