class Solution {
    // 前缀和+哈希表，超牛逼的做法
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;                                           //  用于储存从0到nums.size() - 1之间这nums.size() 个前缀和，以及这些个前缀和对应出现的次数
        int res = 0; 
        int sum = 0;                                                                //  用于计算前缀和的变量
        hash_map[0] = 1;         //  这个元素代表前缀和为0的时候出现的次数，假如sum == k的情况下，sum - k = 0, 也就是说我们前缀和为sum的这个数组元素和为k, 因此res+=1也就是res+=hash[0];
        for (auto num: nums) { 
            sum += num;                                                             //  暴力解法中的第i个前缀和sum(sum[i])
            //  sum - k就是暴力解法中 sum[i] - sum[j-1] = k中的sum[j-1]前缀和，意思是从j到i的子数组满足和为k
            if (hash_map.find(sum - k) != hash_map.end()) res += hash_map[sum-k];   //  在哈希表中找当前i(也就是sum)前缀和的情况下子数组满足和为k的子数组
            if (hash_map.find(sum) != hash_map.end()) hash_map[sum]++;              //  如果这个前缀和在哈希表中出现过，给这个前缀和出现的次数加一，通常情况就是下一个num为0的情况，导致前缀和相等    
            else hash_map[sum] = 1;                                              
        }
        return res;
    }
};