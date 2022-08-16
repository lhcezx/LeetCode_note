//  核心思路就是让整个nums数组中的所有数字和[1, n]数字做异或运算，结果就是缺少的那个数字
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res ^= (nums[i] ^ (i + 1));
        }
        return res;
    }
};