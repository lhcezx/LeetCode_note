class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1));             //  dp[i][j]返回s1的前i个元素和s2的前j个元素能否和s3的前i+j个元素交织
        dp[0][0] = true;                                                  //  base case: 前0个元素代表不存在元素，两个空子串自然能和一个空的s3子串交织
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 && j == 0) continue;
                int k = i + j;              //  s3的指针位置，例如i = 1, j = 0, 我们要判断s1[0]和s3[0]是否相同，也就是s1[i - 1]和s3[i + j - 1]
                if (i - 1 >= 0) {
                //  判断s1前i个元素和s2前j个元素能否和s3的前i+j个元素交织，要先判断s1的前i-1个元素和s2的前j个元素能否和s3的前i+j-1个元素交织，如果可以，则需要判断s1的第i个元素s1[i-1]和s3的第i+j个元素s3[i+j-1]是否相等
                    dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[k - 1]); 
                } 
                //  判断s1前i个元素和s2前j个元素能否和s3的前i+j个元素交织，要先判断s1的前i个元素和s2的前j-1个元素能否和s3的前i+j-1个元素交织，如果可以，则需要判断s1的第i个元素s2[j-1]和s3的第i+j个元素s3[i+j-1]是否相等
                if (j - 1 >= 0) {
                    dp[i][j] |= dp[i][j - 1] && s2[j - 1] == s3[k - 1];
                }
            }
        }
        return dp[n1][n2];
    }
};