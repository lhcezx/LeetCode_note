//  常规思路，乘积最大子数组由dp[i] = max(dp[i - 1] * nums[i], nums[i])状态转移方程进行转移，但是假如dp[i - 1]为正, nums[i]为负，以nums[i]为结尾的最大乘积子数组既不是nums[i] * dp[i - 1], 也不是nums[i]，而是前面某个负数的乘积累乘到i-1再乘以nums[i]，因此我们要分别记录每个位置的最大乘积和最小乘积
//  用dp_max和dp_min分别记录每个位置i上的最大乘积(通常为正)和最小乘积(通常为负)
class Solution {
public:
    int _max(int a, int b, int c) {
        return max(a, max(b, c));
    }

    int _min(int a, int b, int c) {
        return min(a, min(b, c));
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_max(nums);
        vector<int> dp_min(nums);
        int max_val = nums[0];
        for (int i = 1; i < n; i++) {
            dp_max[i] = _max(nums[i], dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]);
            dp_min[i] = _min(nums[i], dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]);
            max_val = _max(max_val, dp_max[i], dp_min[i]);
        }
        return max_val;
    }
};