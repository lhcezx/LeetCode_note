class Solution {
    vector<vector<int>> memo;
public:
    //  函数返回t1[0:i]和t2[0:j]之间的最长公共子序列
    int dp(string& text1, string& text2, int i, int j) {
        if (i < 0 || j < 0) return 0;                   //  base case
        if (memo[i][j] != INT_MIN) return memo[i][j];
        if (text1[i] == text2[j]) return memo[i][j] = dp(text1, text2, i - 1, j - 1) + 1;
        else return memo[i][j] = max(dp(text1, text2, i - 1, j), dp(text1, text2, i, j - 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        memo.assign(n, vector<int> (m, INT_MIN));
        return dp(text1, text2, n - 1, m - 1);
    }
};