//  自顶向下
class Solution {
    vector<vector<int>> memo;
public:
    //  返回s[i, j]内的最长回文子序列
    int dp(string& s, int i, int j) {
        //  base case: i指针若超越j指针，返回0; 若ij指针相等，将回文序列长度加一
        if (i > j) return 0;
        if (i == j) return 1;           
        if (memo[i][j] != -1) return memo[i][j];
        if (s[i] == s[j]) return memo[i][j] = dp(s, i + 1, j - 1) + 2;      //  每次s[i] == s[j] 回文序列长度+2，因为是两个字符
        else return memo[i][j] = max(dp(s, i + 1, j), dp(s, i, j - 1));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memo.assign(n, vector<int> (n, -1));
        return dp(s, 0, n - 1);
    }
};


//  自底向上
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n));                 //  dp数组dp[i][j]代表s[i, j]的最长回文序列长度
        //  base case: 当指针i和j在相同位置的时候，回文序列长度为1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1; 
        }
        //  base case: 当i > j的时候，不存在回文串，长度为0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i][j] = 0;
            }
        }
        //  矩阵的左下三角部分包括对角线都是base case
        for (int i = n - 1; i >= 0; i--) {                          //  遍历顺序i必须从底向上，若从顶向下会因缺失信息而无法正确计算
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;  
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};