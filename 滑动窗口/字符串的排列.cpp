class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> needs, windows;
        int n = s1.size(), m = s2.size();
        int valid = 0;
        int slow = 0, fast = 0;
        for (auto c: s1) needs[c]++;

        while (fast < m) {
            if (needs.count(s2[fast])) {
                windows[s2[fast]]++;
                if (windows[s2[fast]] == needs[s2[fast]]) valid++;
            }
            while (valid == needs.size()) {
                if (fast - slow + 1 == n) return true;
                if (needs.count(s2[slow])) {
                    if (windows[s2[slow]] == needs[s2[slow]]) valid--;
                    windows[s2[slow]]--;
                }
                slow++;
            }
            fast++;
        }
        return false;
    }
};