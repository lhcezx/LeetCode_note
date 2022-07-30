//  dp[i][j]代表当数组nums可选范围为nums[i, j]时，先手玩家获得相对分数, 相对分数即为自己获得的分数为正，对手获得的分数为负，也叫净胜分
//  当甲拿nums[i]时，拿完后乙变成先手，乙的作为先手的净胜分为dp[i+1][j]，甲拿的nums[i] - 乙在nums[i+1,j]上获得的净胜分，就是甲在nums[i, j]上的净胜分
//  同理当甲拿nums[j]时，拿完后乙在nums[i, j-1]区间上作为先手的净胜分为dp[i, j-1]，最终甲在nums[i, j]上的净胜分就是nums[j] - nums[i, j-1];

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp;                                 
        dp.assign(n, vector<int>(n, 0));
        // base case
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];         //  当只有一个数字可以选的时候，只能选这个数字作为净分数

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};