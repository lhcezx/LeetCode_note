class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            if (nums[begin] + nums[end] < target) {
                begin++;
            } else if (nums[begin] + nums[end] > target) {
                end--;
            } else {
                vector<int> ans = {nums[begin], nums[end]};
                return ans;
            }
        }
        return {};
    }
};