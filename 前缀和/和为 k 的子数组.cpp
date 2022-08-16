class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        int sum = 0;
        int res = 0;
        hash_map[0] = 1;                //  当sum = k时，和为k的数组就是sum数组本身
        for (int num: nums) {
            sum += num;                 //  实时的前缀和
            if (hash_map.count(sum - k)) res += hash_map[sum - k];          //  先判断哈希表中是否存在，后将hash_map[sum]++, 为了防止k == 0这种情况
            hash_map[sum]++;
        }
        return res;
    }
};