class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool search_left) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;          //  防止r过大越界
            if (nums[mid] == target) {
                if (search_left) r = mid - 1;   //  如果要寻找target起始位置，即左边界，则收缩右边界
                else l = mid + 1;               //  如果要寻找target种植位置，即右边界，则收缩左边界
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            }
        }
        if (search_left) {                      
            if (l >= nums.size() || nums[l] != target) return -1;   //  如果寻找左边界，则需要判断左边界是否越界
            return l;
        } else {
            if (r < 0 || nums[r] != target) return -1;
            return r;
        }

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(binarySearch(nums, target, true));
        res.push_back(binarySearch(nums, target, false));
        return res;
    }
};