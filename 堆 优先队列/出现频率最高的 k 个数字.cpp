class Solution {
    unordered_map<int, int> hash_map;
    priority_queue<pair<int, int>> heap;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        for (int num: nums) {
            hash_map[num]++;                        //  保存每个数字出现的次数
        }
        for (auto c: hash_map) {
            heap.emplace(c.second, c.first);        //  将数字按照次数排序，出现次数最多的在堆顶
        }
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};