class Solution {
    unordered_map<char, int> cnt_n, cnt_m;      //  哈希表，用于存储字符串t中的每一个字符出现的次数
public:
    bool check() {                              //  判断两个哈希表中sting t的字符的出现次数是否相同
        for (auto c: cnt_n) {
            if (cnt_m[c.first] < c.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int min_len = INT_MAX, min_idx = 0;
        int m = s.length(), n = t.length();
        int slow = 0, fast = 0;                 //  定义快慢指针
        if (n > m) return "";

        for (auto c: t) {
            cnt_n[c]++;
        }

        while (fast < m) {
            if (cnt_n.find(s[fast]) != cnt_n.end()) cnt_m[s[fast]]++;      // 遍历字符串s中的字符，如果该字符在t中出现过，则将其在s的哈希表中+1;
            while (check() && slow <= fast) {
                if (fast - slow + 1 < min_len) {
                    min_len = fast - slow + 1;
                    min_idx = slow;
                }
                if (cnt_n.find(s[slow]) != cnt_n.end()) cnt_m[s[slow]]--;  //  右移动左指针，如果指向的字符在t中出现，则将其次数--
                slow++;
            }
            fast++;
        }
        return min_len == INT_MAX? "": s.substr(min_idx, min_len);
    }
};