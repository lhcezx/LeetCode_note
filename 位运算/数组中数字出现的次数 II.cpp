class Solution {
    unordered_map<int, int> hash_map;
public:
    int singleNumber(vector<int>& nums) {
        for (auto num: nums) {
            if (hash_map.find(num) != hash_map.end()) hash_map[num]++;  //  若num键存在，则将其的值也就是代表这个键出现的次数加一
            else hash_map.insert({num, 1});                             //  若num键不存在，则插入键值对{num, 1}
        }
        for (auto val: hash_map) {
            if (val.second == 1) return val.first;                      //  遍历哈希表，若键值对的值val.second == 1，则证明找到了只出现了一次的数字，即val键
        }
        return 0;
    }
};