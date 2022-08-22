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


//  原地哈希法
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            //  如果数组的索引和索引对应的值相同，则指针前进
            if (nums[nums[i]] == i) {
                i++;
                continue;
            }
            else if (nums[i] == nums[nums[i]]) return nums[i];      //  如果当前索引i对应的值nums[i]和当前值作为索引对应的值nums[nums[i]]相同，则说明数组中存在两个相同值，直接返回。ex: i = 4, nums[i] = 2, nums[nums[i]] = 2
            swap(nums[i], nums[nums[i]]);                           //  否则交换当前值和当前值作为索引对应的值
        }
        return -1;
    }
};