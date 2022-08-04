class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));      //  dp[i][j]返回从[i, j]到达右下角[m - 1, n - 1]共有多少种路径
        dp[m - 1][n - 1] = 1;                           //  base case
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                int right = j + 1 < n ? dp[i][j + 1] : 0;           //  从右边的格子走到终点的走法数量
                int down = i + 1 < m ? dp[i + 1][j] : 0;            //  从下面的格子走到终点的走法数量
                dp[i][j] = right + down;
            }
        }
        return dp[0][0];
    }
};