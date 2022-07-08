class Solution {
    unordered_set<int> hash_set;
    int min = 100, max = -100;
public:
    bool isStraight(vector<int>& nums) {
        for (int num: nums) {
            if (num == 0) continue;
            if (hash_set.find(num) != hash_set.end()) return false;
            hash_set.insert(num);
            if (num < min) min = num;
            if (num > max) max = num;
        }
        if (max - min < 5) return true;
        return false;
    }
};