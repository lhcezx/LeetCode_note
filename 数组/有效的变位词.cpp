class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s == t || s.size() != t.size()) return false;
        vector<int> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }
        int equal = 0;
        for (int c: cnt) if (c == 0) equal++;
        if (equal == 26) return true;
        return false;
    }
};