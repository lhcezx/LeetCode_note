class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1);                     //  dp[i]代表最多可以按i次，屏幕上显示最多的"A"的个数
        // base case
        dp[0] = 0;
        //  对应两种选择, 第i次要么按A, 要么按ctrl+v 才有可能达到最大值
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;             //  当我们每第i次按A
            //  对在第j次开始按ctrl+v做选择，由于ctrlA + ctrlC占两次，因此j从3开始(j也可以从2开始，但相当于什么也没复制)，最多不能超过第i次
            for (int j = 3; j <= i; j++) {     
                dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));            //  从第j次开始到第i次都在按ctrlV
            }
        }
        return dp[n];
    }
};