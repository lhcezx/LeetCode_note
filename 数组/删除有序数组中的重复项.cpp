class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 0;                 //  快慢指针, 快指针在前面，慢指针在后面
        while (fast < nums.size()) {
            if (nums[slow] != nums[fast]) {     //  如果快指针和慢指针的值不相等，则说明快指针到达下一个重复的数字
                slow++;                         //  slow移动到下一个元素，并将下一个元素原地换成下一个重复的数字
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};