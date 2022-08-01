class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));                                    //  dp[i][j] 返回在第i天是否持有股票所能获得的最大利润
        //  base case
        dp[0][0] = 0;
        dp[0][1] = -prices[0] - fee;                                        
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);                   //  如果在第i天未持有股票，则根据在第i天卖出或不卖出计算最值
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);             //  如果在第i天持有股票，则根据在第i天买入或不买入计算最值, 注意这里的每次买入需要计入手续费
        }
        return dp[n - 1][0];
    }
};