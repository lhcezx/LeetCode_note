//  左前缀积数组和右后缀积数组，两个数组在i位置的积left[i] * right[i]即为不包含元素nums[i]的积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};


//  优化版: 不再使用左右前后缀积数组, 用ans数组代替原本的left数组保存前缀积，用right变量作为实时后缀积，从后向前遍历，并且不断更新right变量, 最后更新完整个数组.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];              //  首先将ans数组用左前缀积填满
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * right;
            right *= nums[i];
        }
        return ans;
    }
};