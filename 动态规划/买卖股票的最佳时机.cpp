class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));                 //  dp[i][j]返回在第i天是否持有股票能获得的最大利润，j表示在第i天我们是否持有股票, 0代表未持有股票. 1代表持有股票
        //  base case
        dp[0][0] = 0;               //  第0天未持有股票，利润为
        dp[0][1] = -prices[0];      //  第0天持有股票，代表在第0天买入，利润为-prices[0]
        
        for (int i = 1; i < n; i++) {
            //  dp[i][0]第i天未持有股票能获得最大利润为, 第i-1天也未持有股票获得的最大利润dp[i - 1][0], 和第i-1天持有股票的最大利润dp[i - 1][1] + 在第i天卖掉的股票的利润prices[i]
            //  dp[i][1]第i天持有股票能获得最大利润为, 第i-1天也持有股票获得的最大利润dp[i - 1][1], 和在第i天买入的股票的利润-prices[i - 1]
            //  注意，这里不能写成max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);  因为买卖只能进行一次，dp[i - 1][0]会计算出当第i-1天未持有股票的最大利润，假如在第某天买入然后在某天卖出，第i-1天也是未持有股票的，但已经进行过交易了，所以第i天不能再次买入。因此这里只能进行一次买入，也就是-prices[i-1]
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);            
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }
        return dp[n - 1][0];                    //  在前n-1天买卖股票能获得最大利润，第n-1天一定是没有持有股票的
    }
};