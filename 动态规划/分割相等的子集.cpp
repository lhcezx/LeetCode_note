//  将数组的总和除以2，将问题转换为能否将其中一个子集用和sum / 2的数字装满，将其中一个装满，另一个子集自然而然就是sum / 2了
//  该问题为01背包问题，状态有两个: 1.可以选择的物品范围i; 2.背包的容量 size.
//  状态i由i-1转换而来，判断是否要将nums[i]装入背包: dp[i][size] = dp[i - 1][size] || dp[i - 1][size - nums[i]], 前面对应的是不将nums[i]装进背包，后面对应的是将nums[i]装进背包


//  自顶向下
class Solution {
    vector<vector<int>> memo;
public:
    //  返回能否从[1, i]中的物品里选出正好装满容量为size的背包
    bool dp(vector<int>& nums, int i, int size) {
        // base case
        int j = size;
        if (size == 0) return true;                  //  背包被装满了，返回true
        if (i == -1) return false;                   //  没有可以选择的数字，因此不可能装满
        if (memo[i][j] != -1) return memo[i][j];
        if (size - nums[i] >= 0) {
            return memo[i][j] = dp(nums, i - 1, size) || dp(nums, i - 1, size - nums[i]);       //  dp(nums, i - 1, size)：判断不放nums[i]能否将size装满; dp(nums, i - 1, size - nums[i]) 放nums[i]的话判断是否在[1, i - 1]这些数字中将size - nums[i]装满
        } else {
            return memo[i][j] = dp(nums, i - 1, size);
        }
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false;                 //  无法分割
        int size = sum / 2;
        memo.assign(n, vector<int> (size + 1, -1));   //  重量从0到sum / 2;
        return dp(nums, n - 1, sum / 2);            
    }
};





//  自底向上
//  注意！这里的nums[i - 1]代表的实际是第i个物品，因为物品从1到n编号的
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<vector<bool>> dp;                        //  dp[i][j]代表从[1, i]个数字中，能否选出元素将容量为j的背包正好装满
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false;                 //  无法分割
        int size = sum / 2;
        dp.assign(n + 1, vector<bool> (size + 1, false));       
        
        for(int i = 1; i <= n; i++) {
            dp[i][0] = true;                            //  当背包容量为0，无需添加元素即得背包是满的
            dp[0][i] = false;                           //  当没有可以选择的元素的时候，背包不可能是满的
        }

        for (int i = 1; i <= n; i++) {                  //  由于计算dp[i][j]需要使用dp[i - 1][j]和dp[i - 1][j - nums[i]] 因此可以从左到右，从上到下遍历
            for (int j = 1; j <= size; j++) {
                if (nums[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];            //  nums[i]的重量大于背包容量，放不下
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];      //  dp[i - 1][j]对应不放nums[i], dp[i - 1][j - nums[i]]对应着要准备放nums[i], 所以在[1, i - 1]的数字中能否将容量为j - nums[i]的背包装满
                }
            }
        }
        return dp[n][sum / 2];
    }
};


