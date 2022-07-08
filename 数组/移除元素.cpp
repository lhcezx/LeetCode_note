class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;     // 快慢指针
        while (fast < nums.size()) {
            if (nums[fast] == val) fast++;      //  当快指针找到了Val的时候，快指针++, 慢指针不动
            else {
                nums[slow] = nums[fast];        //  当快指针跳过了val的时候，慢指针还指向val, 此时应该用fast指针的值替换slow指针的值完成原地删除
                fast++;                         //  当快指针不等于val的时候，快慢指针以同样的速度前进
                slow++;
            }
        }
        return slow;            //  这里需要注意输出slow而不是slow + 1, 因为这里是先赋值删除元素，再++,因此我们无法保证++后的slow指向的元素不为val
    }
};