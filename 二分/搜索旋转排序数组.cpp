//  通过每次判断left和mid的值的大小关系即能判断左半数组是完全有序还是右半数组是完全有序
//  mid需要在开头单独判断，左边数组是左闭右开，右边数组是左开右闭
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            //  左半数组为有序数组
            //  这里需要加等号，为的是只有两个数字的情况，只有两个数字mid会先指向第一个数，若不是target则代表是另一个数字，因此我们希望left + 1，只有在第一个判断式中能够left + 1,第二个会让right - 1
            if (nums[0] <= nums[mid]) {                              //  判断是否在左半数组中, 注意左半数组是左闭右开
                if (target >= nums[0] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            //  右半数组为有序数组
            } else {
                if (target > nums[mid] && target <= nums[n - 1]) {  //  判断是否在右半数组中, 左开右闭
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};