//  每个元素最多进入for循环两次: 如果nums[i + 1]存在，nums[i]会被直接跳过, 这里nums[i]进入循环第一次; 当nums[i+1]不存在时，我们要从nums[i]开始一直向前计算连续序列的长度，因此nums[i]前面的连续序列中的数字的会进入while循环，也就是进入for循环第二次.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (int num: nums) {
            hash_set.insert(num);
        }
        int max_len = 0;
        for (int num: nums) {
            int len = 1;
            if (hash_set.count(num + 1)) continue;          //  如果后面有连续的数字存在，则说明以num结尾的一定不是最长的连续序列
            while (hash_set.count(num - 1)) {               //  后面没有连续的数字了，那么num一定是某个连续序列的结尾，一次遍历前面的每一个1连续的数字并计算长度
                num -= 1;
                len += 1;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};