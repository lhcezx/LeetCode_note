class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX / 2);                         //  dp[i]返回需要最少多少个完全平方数才能使得和为n
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {                      //  寻找每一个小于等于i的完全平方数
                dp[i] = min(dp[i], dp[i - j * j] + 1);              //  凑到i的完全平方数个数等于凑到i - j * j的完全平方数个数加1
            }
        }
        return dp[n];
    }
};