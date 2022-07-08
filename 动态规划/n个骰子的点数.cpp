class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> res;
        double dp[70] = {0};                      //  [i][j]空间优化，这里我们删掉了前i个筛子的[i]维度，仅保留了点数j出现的概率[j]维度
        for (int i = 1; i <= 6; i++) {      //  初始化
            dp[i] = 1.0 / 6;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 6*i; j >= i; j--) {      // 这里j需要从后向前 (不明白为什么)
                dp[j] = 0.;                       // 每一步需要将j位置的概率设置为0 (不知道为什么)
                for (int k = 1; k <= 6; k++) {
                    if (j - k < i - 1) break;
                    dp[j] += dp[j-k] * 1.0 / 6;   //  由于筛子点数和为j的之和筛子点数和为j-k相关，实际上与筛子的个数没有直接关系。
                }
            }
        }
        for (int i = n; i <= 6*n; i++) {
            res.push_back(dp[i]);
        }
        return res;
    }
};