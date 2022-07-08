class Solution {
    unordered_map<int, int> hash_map;
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            if (hash_map.find(nums[i]) != hash_map.end()){
                return nums[i];
            } else {
                hash_map[nums[i]];
            }
        }
        return -1;
    }
};