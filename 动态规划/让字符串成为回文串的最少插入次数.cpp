class Solution {
    vector<vector<int>> memo;
public:
    //  返回s[i, j] 变成回文串的最少插入次数
    int dp(string& s, int i, int j) {
        //  base case
        if (i >= j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        if (s[i] == s[j]) return memo[i][j] = dp(s, i + 1, j - 1);
        else return memo[i][j] = min(dp(s, i + 1, j), dp(s, i, j - 1)) + 1;   //  s[i] != s[j]，将j后面插入一个s[i]: dp(s, i + 1, j) 或将i前面插入一个s[j]: dp(s, i, j - 1), 两种情况操作数都要+1
    }

    int minInsertions(string s) {
        int n = s.size();
        memo.assign(n, vector<int> (n, -1));
        return dp(s, 0, n - 1); 
    }
};