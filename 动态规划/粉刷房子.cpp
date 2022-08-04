class Solution {
public:
    int _min(int a, int b, int c) {
        return min(a, min(b, c));
    }
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3));                             //  dp[i][j]返回将刷完前i个房子的最小成本，第i个房子的颜色为j
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
;
                dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + costs[i][j];
            }
        }
        return _min(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]);
    }   
};