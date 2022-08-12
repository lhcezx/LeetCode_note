//  我们希望将数字的高位的较小的值和数字低位较大的值交换，这样就能增大数字的值. 同时我们希望增大的幅度尽可能地小，因此我们希望左边较小的数字尽可能的靠右，右边较大的那个数字尽可能的小一些，贪心思路

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        //  从后向前找第一对左边数字小于右边的数对
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        //  如果最后i == -1，说明从头到尾的数字排列是降序，因此已经是字典序中的最大值了，直接将数组翻转，返回最小值
        if (i == -1) {
            reverse(nums.begin() , nums.end());
            return;
        }
        //  由于从nums[i+1..n]为降序排列，因此我们从后向前找第一个比nums[i]大的数字
        int j = n - 1;
        while (j > i && nums[i] >= nums[j]) j--;
        swap(nums[i], nums[j]);
        //  将nums[i+1 : n-1]改为升序排列
        reverse(nums.begin() + i + 1, nums.end());
    }
};