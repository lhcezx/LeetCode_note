//  状态是金额的数量，根据每次选择的币种状态会发生转移, base case是当amount为0的时候，最少的硬币个数为0
class Solution {
    vector<int> dp_table;                         //  代表凑够amount所需要的硬币个数
public:
    int coinChange(vector<int>& coins, int amount) {
        dp_table.assign(amount + 1, 1000);        //  amount + 1个位置，每个位置上的值都是1000
        return dp(coins, amount);
    }

    int dp(vector<int>& coins, int amount) {                            //  返回要求金额amount给定情况下用最少的硬币能够达到amount的硬币数量
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (dp_table[amount] != 1000) return dp_table[amount];          //  dp备忘录，防止重复计算
        int res = INT_MAX;
        for (int coin: coins) {
            int subproblem = dp(coins, amount - coin);                  //  计算子问题结果
            if (subproblem == -1) continue;
            res = min(res, subproblem + 1);
        }
        dp_table[amount] = (res == INT_MAX? -1: res);                   //  记录amount给定情况下最少的硬币数量
        return dp_table[amount];
    }
};