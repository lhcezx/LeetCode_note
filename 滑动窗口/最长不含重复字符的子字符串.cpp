class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, i = -1;
        unordered_map<int, int> hash_map;

        for (int j = 0; j < s.length(); ++j) {
            if (hash_map.find(s[j]) != hash_map.end()) {
                i = max(i, hash_map.at(s[j]));
            }
            hash_map[s[j]]= j;
            res = max(res, j - i);
        }
        return res;
    }
};