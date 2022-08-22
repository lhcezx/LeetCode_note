//  在为缺失数字的那半数组中，i = nums[i], 在缺失的那半数组中 nums[i] > i
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid) {
                right = mid - 1;
            } else if (nums[mid] == mid) {
                left = mid + 1;
            }
        }
        return left;
    }
};

//  位运算

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        int num = 0;
        //  数字从[0, n-1]，索引为[0, n-2]，因此需要在循环结束后在异或n-1
        for (int i = 0; i < n - 1; i++) {
            num ^= (i ^ nums[i]);
        }
        num ^= (n - 1);
        return num;
    }
};