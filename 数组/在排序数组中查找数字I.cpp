class Solution {
public:
    int binary_reserch(vector<int>& nums, int target, bool lower = false){
        int left = 0, right = (int)nums.size() - 1, ans = nums.size();
        int mid = 0;
        while(left <= right) {
            mid = (left + right) / 2;
            if ((target >= nums[mid] && lower == false) || (target > nums[mid] && lower)){
                left = mid + 1;
            } else {
                right = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
        int left_bound = binary_reserch(nums, target, true);
        int right_bound = binary_reserch(nums, target) - 1;
        if (left_bound <= right_bound && right_bound < nums.size() && nums[left_bound] == target && nums[right_bound] == target){
            return right_bound - left_bound + 1;
        }
        return 0;
    }
};