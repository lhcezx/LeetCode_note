//  滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int i = 0, j = 0;
        unordered_map<char, int> mp;            //  每个出现的字符的下标
        while (j < s.length()) {
            if (!mp.count(s[j])) {
                mp[s[j]] = j;
                j++;
            } else {
                max_len = max(max_len, j - i);
                int idx = mp[s[j]];
                while (i <= idx && i < j) {
                    mp.erase(s[i++]);
                }
            }
        }
        max_len = max(max_len, j - i);
        return max_len;
    }
};

