class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], pre = 0;
        for (int num: nums) {
            // res = max(res, max(pre + num, num));
            pre = max(pre + num, num);
            res = max(res, pre);
        }
        return res;
    }
};