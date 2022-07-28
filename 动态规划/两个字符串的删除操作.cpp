class Solution {
    vector<vector<int>> memo;
public:
    //  求word1[0:i], word2[0:j]的最长公共子序列长度
    int dp(string& word1, string& word2, int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        if (word1[i] == word2[j]) return memo[i][j] = dp(word1, word2, i - 1, j - 1) + 1;           //  若相等，求word1[0:i-1], word2[0:j-1]的最长公共子序列
        else return memo[i][j] = max(dp(word1, word2, i - 1, j), dp(word1, word2, i, j - 1));       //  若不相等，求word1[0:i-1], word2[0:j]的最长公共子序列和word1[0:i], word2[0:j-1]的最长公共子序列，两个取最大值
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memo.assign(n, vector<int> (m, -1));
        int len_subseq = dp(word1, word2, n - 1, m - 1);
        return n - len_subseq + m - len_subseq;
    }
};