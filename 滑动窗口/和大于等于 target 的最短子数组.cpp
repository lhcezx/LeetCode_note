class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow = 0, fast = 0;             //  滑动窗口的左指针和右指针
        int min_len = 1e5;
        int sum = 0;
        while (fast < nums.size()) {
            sum += nums[fast];              //  每次fast都会右划一位，因此sum需要加上这位
            while (sum >= target) {
                min_len = min(fast - slow + 1, min_len);
                sum -= nums[slow];
                slow++;
            } 
            fast++;
            
        }
        return min_len == 1e5? 0: min_len;
    }
};