//  由于是环形房屋，因此第一个房屋nums[0]和最后一个房屋nums[n-1]是挨着的，因此只有两种情况可以得到最大值: 一种是偷第一个房屋，不偷最后一个房屋; 第二种是偷最后一个房屋，不偷第一个房屋，由于涉及到开头和结尾，因此用i, j代表nums[i, j]能偷到的最大金额
//  自顶向下
class Solution {
    vector<vector<int>> memo;
public:
    //  返回数组nums[i, j]中能抢到的最大金额
    int dp(vector<int>& nums, int i, int j) {
        int n = nums.size();
        if (i > j) return 0;
        if (i == j) return nums[i];
        if (memo[i][j] != -1) return memo[i][j];
        return memo[i][j] = max(dp(nums, i, j - 2) + nums[j], dp(nums, i, j - 1)); 
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, vector<int> (n, -1));
        if (n == 1) return nums[0];        //  需要处理只有一个屋子的特殊情况，只有一个物子代表它既是第一个，也是最后一个，两种情况都不能偷会返回0，但实际上是只偷这一个屋子
        //  dp(nums, 0, n - 2)代表从nums[0:n-2]中能偷到的最大金额，对应不偷最后一个房屋的情况; dp(nums, 1, n - 1)代表从nums[1:n-1]中能偷到的最大金额，对应不偷第一个房屋的情况     
        return max(dp(nums, 0, n - 2), dp(nums, 1, n - 1));     
    }
};


//  自底向上
class Solution {
public:
    //  函数返回从nums[start:end]所能偷取到的最大金额
    int robRange(vector<int>& nums, int start, int end) {
        int n = nums.size();
        vector<int> dp(n, 0);                           //  dp[i]返回从nums[start:i]所能取得的最大金额
        if (start == end) return nums[start];           //  当start == end, 区间内只有一个房屋，因此直接返回这个房屋的价值
        dp[start] = nums[start];                        //  base case
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];                                         //  当只有一个屋子的时候，第一个就是最后一个，因此直接返回该房屋价值
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));     //  robRange(nums, 0, n - 2): 返回从nums[0:n-2]偷到的最大价值, 对应不偷最后一个房屋; robRange(nums, 1, n - 1): 返回从nums[1:n-1]偷到的最大价值，对应不偷第一个房屋
    }
};


//  空间优化版
class Solution {
public:
    //  函数返回从nums[start:end]所能偷取到的最大金额
    int robRange(vector<int>& nums, int start, int end) {
        int n = nums.size();
        vector<int> dp(n, 0);                           //  dp[i]返回从nums[start:i]所能取得的最大金额
        if (start == end) return nums[start];           //  当start == end, 区间内只有一个房屋，因此直接返回这个房屋的价值
        int dp_i_2 = nums[start];                        //  base case
        int dp_i_1 = max(nums[start], nums[start + 1]);
        int dp_i = dp_i_1;
        for (int i = start + 2; i <= end; i++) {
            dp_i = max(dp_i_2 + nums[i], dp_i_1);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];                                         //  当只有一个屋子的时候，第一个就是最后一个，因此直接返回该房屋价值
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));     //  robRange(nums, 0, n - 2): 返回从nums[0:n-2]偷到的最大价值, 对应不偷最后一个房屋; robRange(nums, 1, n - 1): 返回从nums[1:n-1]偷到的最大价值，对应不偷第一个房屋
    }
};