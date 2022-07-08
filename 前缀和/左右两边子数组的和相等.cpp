class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sums;
        int n = nums.size() - 1;
        int sum = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);  //  整个数组的元素总个数
        for (int i = 0; i < nums.size(); i++) {
            if (sum == total - nums[i] - sum) return i;       //  当左边前缀和和右边后缀和相等的时候，直接输出下标
            sum += nums[i];
        }
        return -1;
    }
};