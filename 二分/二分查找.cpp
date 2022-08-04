class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (nums[left] == target) return left;
        else return -1;
    }
};