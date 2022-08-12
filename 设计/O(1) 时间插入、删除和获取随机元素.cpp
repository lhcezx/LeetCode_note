class RandomizedSet {
    unordered_map<int, int> hash_map;       //  用哈希表存储每一个值及其下标
    vector<int> nums;                       //  将每一个值放入nums中，由于哈希表无法做到等概率随机抽取一个值，因此我们仍然需要数组来做这件事
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (hash_map.find(val) != hash_map.end()) return false;
        nums.push_back(val);                //  如果不存在则将val存入数组尾部
        hash_map[val] = nums.size() - 1;    //  保存val的值及其索引
        return true;
    }
    
    bool remove(int val) {
        if (hash_map.find(val) == hash_map.end()) return false;
        int idx = hash_map[val];                //  获得要删除元素的下标
        nums[idx] = nums.back();                //  将要删除的元素和最有一个元素交换 (具体操作是将最后一个元素值覆盖idx元素的值)
        nums.pop_back();                        //  将该元素从数组中删除
        hash_map[nums[idx]] = idx;              //  要删除元素的下标就变到最后下标，交换的元素的下标变为idx
        hash_map.erase(val);                    //  将该元素从哈希表中删除
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
