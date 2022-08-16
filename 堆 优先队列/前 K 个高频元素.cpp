class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        for (int num: nums) {
            hash_map[num]++;
        }
        auto cmp = [&](const auto &a, const auto &b){return a.second > b.second;};                  //  最小堆, 堆内保存k个元素，根据出现的次数排序，次数最小的放在最上面
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (auto [num, counter]: hash_map) {
            if (pq.size() >= k) {
                if (pq.top().second < counter) {                                                    //  对比要入堆的元素出现次数是否比当前最小的要大，若是则入堆，否则跳过
                    pq.pop();
                    pq.emplace(num, counter);
                }
            } else {
                pq.emplace(num, counter);
            }
        }
        vector<int> res;
        //  堆内元素就是出现次数最大的k个元素
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};