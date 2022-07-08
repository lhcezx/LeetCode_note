class Solution {
public:
    int getID(int num, long size) {                  //  num为数组中元素的值，size是每个桶的大小, 桶内元素之差小于等于t
        // 每个桶内元素必然为size + 1 个，因此分母固定size + 1. 当num大于等于0由于从0开始，假设t = 9，那么元素[0, 9]都在第一个桶内，当nums为负的时候，[-1, -10]在编号为-1的桶内，因为从-1开始因此需要j将num + 1, 同时编号从-1开始因此需要-1
        return num >= 0 ? num / (size + 1): (num + 1) / (size + 1) - 1;       
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> hash_map;                   //  哈希表保存桶的编号以及对应的桶内元素
        for (int i = 0; i < nums.size(); i++) {
            int id = getID(nums[i], t);
            if (hash_map.count(id)) return true;            //  如果同一个桶内已经有元素，则直接返回true
            // 查看左边桶，如果存在元素并且在区间[nums[i] - t, nums[i]]之间，则符合要求。这里需要注意越界，如果nums[i] - t小于INT_MIN。则将左界提高到INT_MIN
            else if (hash_map.count(id - 1) && hash_map[id - 1] >= max(INT_MIN + t, nums[i]) - t) return true;       
            //  查看右边桶，如果存在元素并且在区间[nums[i], nums[i] + t]之间，则符合要求，注意越界，如果nums[i] + t 大于INT_MAX, 则将右边界缩小到INT_MAX
            else if (hash_map.count(id + 1) && hash_map[id + 1] <= min(INT_MAX - t, nums[i]) + t) return true;       
            hash_map[getID(nums[i], t)] = nums[i];                                             //  将桶内放入元素的志，注意一个桶内至多有一个元素，因为当存在两个元素时会直接返回true
            if (hash_map.size() > k) hash_map.erase(getID(nums[i - k], t));                             //  窗口滑动时，删除滑过的元素，加入新元素
        }
        return false;
    }
};