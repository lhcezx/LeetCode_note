//  由于硬币可以使用无限次，因此这是一个完全背包的问题
class Solution {
    vector<vector<int>> memo;
public:
    //  返回从coins[0, i]中选择的硬币，刚好装满容量为amount的背包的硬币组合数
    int dp(vector<int>& coins, int i, int amount) {
        if (amount == 0) return 1;                  //  当背包容量为0，没有任何硬币可以放入, 只有这一种组合数
        if (i == -1) return 0;                      //  当没有可以选择的硬币时，组合数为0
        int j = amount;
        if (memo[i][j] != -1) return memo[i][j];
        if (coins[i] > amount) {
            return memo[i][j] = dp(coins, i - 1, j);            //  coins[i]放入后会超过背包容量，因此不放入。在不放入的情况下等于从[0, i - 1]的硬币种类中的正好容量为amount的组合数
        } else {
            //  如果coins[i]可以放入背包，则从[0, i]的硬币种类中满足总额为amount的硬币组合数为，放入coins[i]和不放coins[i]两种情况对应的硬币组合之和, 即dp(coins, i - 1, j)和dp(coins, i, j - coins[i])
            //  由于这里是完全背包问题，因此即使我们放入了一个coins[i]以后，仍然可以继续放coins[i]，因此dp(coins, i, j - coins[i])。如果是01背包问题，那么这里应该写dp(coins, i - 1, j - coins[i])， 因为coins[i]已经被用过了，不能重复使用
            return memo[i][j] = dp(coins, i - 1, j) + dp(coins, i, j - coins[i]);             
        }
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memo.assign(n, vector<int> (amount + 1, -1));
        return dp(coins, n - 1, amount);
    }
};