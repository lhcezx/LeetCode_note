//  回溯
class Solution {
    int res = 0;
public:
    void backtrack(vector<int>& nums, int target, int i, int sum) {
        if (i == nums.size()) {
            if (sum == target) res++;
            return;
        }
            
        sum += nums[i];
        backtrack(nums, target, i + 1, sum);
        sum -= nums[i];

        sum -= nums[i];
        backtrack(nums, target, i + 1, sum);
        sum += nums[i];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        return res;
    }
};


//  自顶向下DP

//  A集合代表+号元素的集合, B集合代表-号元素的绝对值集合. sumA - sumB = target -> sumA = target + sumB -> 2sumA = target + nums -> sumA = (target + nums) / 2; 问题转换为了01背包问题，之所以采用这样的转换，是因为如果直接让函数的意义为返回结果等于target的表达式的数目，我们在状态转移的过程可能会有容量j小于0的情况出现，因此必须转化问题为正整数
//  需要注意的是这里的base case和有些背包问题不完全相同，区别点在于处理memo[...][0]这个情况，对于我们可以选择的背包中的物品，如果体积一定不为零(选择的数是正整数)，那么我们可以直接将memo[...][0]设置为1，意为当背包容量为0的时候，什么元素都不放是唯一的选择. 但本题情况下，数组中的元素可以为0，例如 nums = {0, 0, 0}，此时dp[2][0]的结果就不是0了，因为我们可以有多种选择将这些0放入背包中

class Solution {
    vector<vector<int>> memo;
public:
    //  返回运算结果等于(target + sum) / 2的表达式的数目
    int dp(vector<int>& nums, int i, int j) {
        if (i == -1) {
            if (j == 0) return 1;       
            return 0;
        }
        if (memo[i][j] != -1) return memo[i][j];
        if (nums[i] > j) {
            return memo[i][j] = dp(nums, i - 1, j);
        } else {
            return memo[i][j] = dp(nums, i - 1, j - nums[i]) + dp(nums, i - 1, j);
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(target) || (sum + target) % 2 != 0) return 0;
        memo.assign(n, vector<int> (target + sum + 1, -1));
        return dp(nums, n - 1, (target + sum) / 2);
    }
};



//  自底向上DP

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp;                                                   //  dp[i][j]返回当可选数字从1到i，背包容量为j时，正好装满背包的装法有多少
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(target) || (sum + target) % 2 != 0) return 0;
        int new_sum = (target + sum) / 2;
        dp.assign(n + 1, vector<int> (new_sum + 1));               //  i从0到n，j从0到target_sum
        
        // base case
        dp[0][0] = 1;   // 假设nums编号从1到n，当i = 0时，代表没有可以选的元素，当没有元素可以选择的时候，只有一种选择就是什么都不放
        //  当背包容量不为0时，我们没有可以选择放入背包的元素，因此没有方案能够达到背包容量，方案数 = 0；
        for (int j = 1; j <= new_sum; j++) {
            dp[0][j] = 0;                               
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= new_sum; j++) {
                if (nums[i - 1] > j) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[n][new_sum];
    }
};


//  没有memo的动态规划直接做法

class Solution {
public:
    //  返回从1到i个数中，目标和为j的组合数目
    int dp(vector<int>& nums, int i, int j) {
        if (i == -1) {
            if (j == 0) return 1;
            return 0;
        }
        //  对应两种选择，nums[i]为正号或nums[i]为负号
        return dp(nums, i - 1, j - nums[i]) + dp(nums, i - 1, j + nums[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return dp(nums, n - 1, target);
    }
};


//  带memo的直接DP
class Solution {
    unordered_map<string, int> memo;
public:
    //  返回从1到i个数中，目标和为j的组合数目
    int dp(vector<int>& nums, int i, int j) {
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];
        if (i == -1) {
            if (j == 0) return 1;
            return 0;
        }
        //  对应两种选择，nums[i]为正号或nums[i]为负号
        return memo[key] = dp(nums, i - 1, j - nums[i]) + dp(nums, i - 1, j + nums[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return dp(nums, n - 1, target);
    }
};