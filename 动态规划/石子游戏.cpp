// 详细细节见预测赢家.cpp

// 区间dp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp;                     //  dp[i][j]代表piles可选的范围为piles[i, j]时，先手玩家所能获得的最大净分数
        int n = piles.size();
        dp.assign(n, vector<int> (n));
        // base case
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};



// 状态压缩版
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n);                     //  dp[i][j]代表piles可选的范围为piles[i, j]时，先手玩家所能获得的最大净分数
        // base case
        for (int i = 0; i < n; i++) {
            dp[i] = piles[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                //  dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);  
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] > 0;
    }
};