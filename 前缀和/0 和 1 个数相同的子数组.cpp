class Solution {
    //  含有相同数量的0和1的连续子数组可以转化为，这些个子数组中0和1的数量之差为0，如果将0看作-1，则数组元素之和为0
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash_map;               //  哈希表的键永远都代表前缀和!!! 值可以根据题目对应不同的情况，在本题中值代表某个前缀和第一次出现的下标
        int sum = 0, max_len = 0;
        hash_map[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) sum += -1;                //  我们把数组中的0看作-1
            else sum += 1;                              //  我们把数组中的1仍然看作1
        
            if (hash_map.count(sum)) {                  //  如果某个子数组前缀和在哈希表中出现过，说明当前子数组和前面的子数组的前缀和相等，那么他们的差值为0，说明他们之间的子数组元素和为0
                int first_idx = hash_map[sum];          //  找到它第一次出现的时候的末尾元素的下标
                max_len = max(max_len, i - first_idx);   
            } else {
                hash_map[sum] = i;
            }
        }
        return max_len;
    }
};