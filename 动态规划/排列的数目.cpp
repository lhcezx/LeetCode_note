//  完全背包问题，这里和零钱兑换II不一样的是，如果包内装的数字相同，但是装入顺序不同，则被视为不同的方法
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);                     //  dp[i]返回凑出目标和为i的组合方法有多少种
        //  base case
        dp[0] = 1;          
        for (int i = 1; i <= target; i++) {
            for (auto num: nums) {
                if (num <= i) dp[i] += dp[i - num];     //  当num为和为i的组合的最后一个元素的时候，dp[i] += dp[i - num]
            }
        }
        return dp[target];
    }
};