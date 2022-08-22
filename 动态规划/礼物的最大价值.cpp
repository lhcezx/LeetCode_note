class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int up = j - 1 >= 0 ? dp[i][j - 1] : 0;
                int left = i - 1 >= 0 ? dp[i - 1][j] : 0;
                dp[i][j] = max(left, up) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};