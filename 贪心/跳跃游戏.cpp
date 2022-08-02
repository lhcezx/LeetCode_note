class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        //  遍历每一个位置，注意这里不需要遍历最后一个索引
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);          //  计算在每一个位置上能够跳到最远的地方
            if (farthest <= i) return false;                //  如果在某个位置上，我们有farthest = i, 说明nums[i] == 0, 且前面的每个位置能跳到的最远的位置小于等于i, 因此无法跳到终点
        }
        return farthest >= n - 1;
    }
};