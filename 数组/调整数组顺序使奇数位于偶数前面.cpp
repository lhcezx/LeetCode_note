class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            while (begin < end && nums[begin]%2 != 0) {
                begin++;
            }
            while (begin < end && nums[end]%2 == 0) {
                end--;
            }
            swap(nums[begin], nums[end]);
        }
        return nums;
    }
};