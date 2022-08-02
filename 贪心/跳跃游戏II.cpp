//  动态规划
class Solution {
    vector<int> memo;
public:
    //  返回从i跳到最后一个位置所需要的最小跳跃次数
    int dp(vector<int>& nums, int i) {
        int n = nums.size();
        if (i >= n - 1) return 0;
        if (memo[i] != -1) return memo[i];
        //  base case: 从最后一个位置跳到最后需要的步数为0
        //  做选择，选择一次要跳的步数
        int res = INT_MAX / 2;
        for (int k = 1; k <= nums[i]; k++) {
            int subProb = dp(nums, i + k);          //  从第i + k位置到最后一个位置所需要的最小跳跃次数
            res = min(res, subProb + 1);
        }
        return memo[i] = res;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, -1);
        return dp(nums, 0);
    }
};

//  贪心

//  本题到end才counter++，不代表当i到end位置才跳跃，而是通过i从前一个farthest遍历到下一个farthest，之间记录的从某个位置能跳到的最远距离来判断要跳到哪里
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0, farthest = 0;
        int counter = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);              //  遍历每一个位置能跳到的最远位置，用farthest记录那个最远的位置
            if (i == end) {                                     //  end从0开始，到nums[0] + 0, 再到从0到nums[0]之间记录的那个farthest, 依次进行直到到达终点. end会从一个farthest变到下一个farthest, 直到到达终点
                counter++;
                end = farthest;
                if (end >= n - 1) break;                        //  当我们到达了最后一个位置，停止遍历
            }
        }
        return counter;
    }
};