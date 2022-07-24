//  每个元素最多进入for循环两次: 如果nums[i - 1]存在，nums[i]会被直接跳过, 这里nums[i]进入循环第一次; 当nums[i-1]不存在时，我们要从nums[i]开始一直向后计算连续序列的长度，因此nums[i....]后面的会进入while循环，也就是进入for循环第二次.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (int i = 0; i < nums.size(); i++) {
            hash_set.insert(nums[i]);
        }
        int max_len = 0;
        for (auto num: nums) {
            if (hash_set.count(num - 1)) continue;                //  因为如果num-1存在，那么从num开始的最长连续序列肯定比从num-1开始的序列短，因此我们直接跳过计算num-1存在的时num的长度
            int len_seq = 1;
            int cur_num = num;
            while (hash_set.count(cur_num + 1)) {
                cur_num += 1;
                len_seq ++;
            }
            max_len = max(max_len, len_seq);
        }
        return max_len;
    }
};