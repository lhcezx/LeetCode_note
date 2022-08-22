class Solution {
public:
    int left_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int right_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

    int search(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int left = max(left_bound(nums, target), 0);
        int right = min(right_bound(nums, target), n - 1);
        return right - left + 1;
    }
};