class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));              //  dp[i][j] 返回在第i天是否持有股票所能获得的最大利润
        if (n == 1) return 0;
        //  base case 第0天 i == 0
        dp[0][0] = 0;                                           //  当第0天未持有股票时，利润为0
        dp[0][1] = -prices[0];                                  //  当第0天持有股票时，则代表第0天买入了股票
        //  base case 第1天 i == 1，之所以在这里加了i == 1的base case，是因为后面dp[i][1]依赖于dp[i - 2]，会造成越界问题
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);         //  如果第一天没有股票，有可能是第0天就没有股票或者第0天买入第1天卖出
        dp[1][1] = max(dp[0][1], -prices[1]);                   //  如果第一天有股票，那可能是第0天买入的，也有可能是当天买入的
        for (int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);             //  如果在第i天未持有股票，则根据在第i天卖出或不卖出计算最值
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);             //  如果在第i天持有股票，则根据在第i天买入或不买入计算最值，注意这里是dp[i-2][0]而不是dp[i-1][0], 因为dp[i-1][0]包含了在第i-1天卖出的情况，此时不能在第i天买入
        }
        return dp[n - 1][0];
    }
};