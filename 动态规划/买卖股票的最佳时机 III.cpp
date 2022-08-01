class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_k = 2;                                  //  最多允许的交易次数
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (max_k + 1, vector<int>(2)));          //  dp[i][k][j] 返回在第i天是否持有股票且最多交易k次能获得的最大利润, 注意: 一次交易包括一次买入和一次卖出
        //  base case
        //  //  k == 0时的base case: 当k为0时，不允许交易，因此最大利润为0
        for (int i = 0; i < n; i++) {
            dp[i][0][0] = 0;                
            dp[i][0][1] = 0;
        }
        //  i == 1时的base case: 当k不为0时，若第一天持有股票，那么就是第一天买入股票，利润为-prices[0]
        for (int k = 1; k <= max_k; k++) {
            dp[0][k][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= max_k; k++) {
                //  dp[i][0][k]代表在第i天未持有股票且最多交易k次能获得的最大利润，如果第i天什么都做不做，那么利润等于dp[i-1][0][k]也就是第i-1天未持有股票最多交易k次能获得的最大利润.
                //  如果第i天买入股票，那么要在第i-1天的交易次数上限增加一次, 对应的第i天的最大利润为dp[i][1][k]，与之对应的第i-1天的最大利润为dp[i-1][0][k-1]，加上在第i天的买入，也就是-prices[i].
                dp[i][k][0] = max(dp[i - 1][k][0] ,dp[i - 1][k][1] + prices[i]);      
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);         
            }
        }
        return dp[n - 1][max_k][0];
    }
};