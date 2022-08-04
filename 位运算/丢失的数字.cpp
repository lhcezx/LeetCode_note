//  n个数字的数组，索引从[0, n - 1], 我们将索引++变成[1, n]，让所有数组中的数字和索引异或运算，最后能找到那个缺失的数字
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res ^= (nums[i] ^ (i + 1));
        }
        return res;
    }
};