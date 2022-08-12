class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            if (hash_map.count(target - nums[i])) {
                return {i, hash_map[target - nums[i]]};
            } else hash_map[nums[i]] = i;
        }
        return {};
    }
};