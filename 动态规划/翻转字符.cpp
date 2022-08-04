class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2));          // dp[i][j]表示前i个字符为单调递增的最小翻转次数，j代表第i位是0或1
        // base case
        if (s[0] == '0') {
            dp[0][0] = 0;
            dp[0][1] = 1;
        } else {
            dp[0][0] = 1;
            dp[0][1] = 0;
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {       //  若第i位为1
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);         //  前i为为单调递增且第i位为1的最小翻转次数
                dp[i][0] = dp[i - 1][0] + 1;                        //  前i为为单调递增且第i位为0的最小翻转次数
            } else {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
                dp[i][0] = dp[i - 1][0];
            }
        }
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};

