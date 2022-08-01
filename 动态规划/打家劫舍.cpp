//  自顶向下
class Solution {
    vector<int> memo;
public:
    //  返回偷nums[0:k]的最大金额                                      
    int dp(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return nums[0];             //  base case
        if (k < 0) return 0;
        if (memo[k] != -1) return memo[k];
        //  做选择，状态转移
        //  dp(nums, k - 2) + nums[k]: 偷第k家，那么就不能偷第k-1家了，结果为nums[0:k-2]能偷到的最大价值加nums[k];  dp(nums, k - 1): 不偷第k家，结果为从nums[0:k-1]能偷盗的最大价值
        //  之前我会有疑问，为什么偷了第k家得到nums[k]，然后就要和dp(nums, k-2)相加，为什么不是dp(nums, k-1) ? dp(nums, k-1)也不一定一定会偷第nums[k-1]家啊，实际上如果dp(nums, k-1)不偷第nums[k-1]家，那么它能获得的最大值就和dp(nums, k-2)是一样的
        return memo[k] = max(dp(nums, k - 2) + nums[k], dp(nums, k - 1));   
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, -1);
        return dp(nums, n - 1);
    }
};


//  自底向上
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);             // dp[i]返回从nums[0:i]所能偷到的最大金额
        if (n == 1) return nums[0];      
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);        
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};




//  空间优化版
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp;
        int n = nums.size();
        int dp_i_2 = 0, dp_i_1 = nums[0], dp_i = dp_i_1;
        for (int i = 2; i <= n; i++) {
            dp_i = max(dp_i_1, dp_i_2 + nums[i - 1]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};