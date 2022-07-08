class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid = nums.size() - 1;
        while(left <= right){
            mid = (right + left) / 2;
            if (nums[mid] == mid){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }
};