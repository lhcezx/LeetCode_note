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


//  完全背包思路 dp

class Solution {
    vector<vector<int>> memo;                                  
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); 
        memo.assign(n, vector<int> (amount + 1, -100));        //  amount + 1个位置，用-100初始化
        int res = dp(coins, n - 1, amount);
        return res == 1e5 ? -1 : res;
    }

    //  返回从coins[0, i]中选择硬币，正好凑到金额amount的情况下用使用最少的硬币数量
    int dp(vector<int>& coins, int i, int amount) {       
        int j = amount;                     
        if (amount == 0) return 0;                            //  金额为0的时候，需要0个硬币能凑出0
        if (i == -1) return 1e5;                              //  代表凑不出金额，这个base case很关键，不可以返回0，否则会被当作用0个硬币就能凑到amount，因此要返回一个很大的数字，因为后面会用Min函数
        if (memo[i][j] != -100) return memo[i][j];       
        //  在背包容量能放下coins[i]的情况下并且使用[0, i]这些币种能够正好凑齐j-coins[i]的金额时, 对将coins[i]放入背包和不放入背包两种情况用到的硬币数量取最小值
        if (amount >= coins[i] && dp(coins, i, j - coins[i]) != 1e5) {          
            return memo[i][j] = min(dp(coins, i, j - coins[i]) + 1, dp(coins, i - 1, j));
        } else {
        //  当背包容量不足，或使用[0, i]的币种无法凑齐j - coins[i]时，不将coins[i]放入背包，这里的dp(coins, i - 1, j)也可能凑不出来amount
            return memo[i][j] = dp(coins, i - 1, j);
        }

    }
};