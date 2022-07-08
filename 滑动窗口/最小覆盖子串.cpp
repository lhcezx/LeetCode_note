class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> needs, windows;
        int n = t.size(), m = s.size();
        int min_len = INT_MAX, min_idx = 0;
        int slow = 0, fast = 0;
        int valid = 0;              //  用于统计windows表中字符出现次数大于等于needs表中对应的字符的变量
        if (n > m) return "";
        for (auto c: t) needs[c]++;

        while (fast < s.size()) {
            if (needs.count(s[fast])) {
                windows[s[fast]]++;       //  如果字符s[fast]出现在前面保存的needs哈希表中，则将其在windows表中++
                if (windows[s[fast]] == needs[s[fast]]) valid++;
            }
            while (valid == needs.size()) {
                if (fast - slow + 1 < min_len) {
                    min_len = fast - slow + 1;
                    min_idx = slow;
                }
                if (needs.count(s[slow])) {                     //  判断s[slow]元素是否在needs哈希表中出现
                    windows[s[slow]]--;
                    if (windows[s[slow]] < needs[s[slow]]) valid--;         //  若windows中该元素数量小于needs中该元素的数量，由于我们要移除slow元素，因此valid--
                   
                    
                }
                slow++;
            }
            fast++;
        }
        return min_len == INT_MAX? "": s.substr(min_idx, min_len);
    }
};