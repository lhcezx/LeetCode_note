class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> cnt(26);
        int m = s.length(), n = p.length();
        if (n > m) return res;
        for (int i = 0; i < n; i++) {
            cnt[p[i] - 'a']--;          //  p串每个字符出现时让该字符次数--
            cnt[s[i] - 'a']++;          //  s串每个字符出现时让该字符次数++
        }
        int diff = 0;                   //  统计共有多少个字符次数不为0
        for (int i: cnt) {
            if (i) diff++;
        }
        if (diff == 0) res.push_back(0);
        for (int i = n; i < m; i++) {
            int last = s[i] - 'a', first = s[i - n] - 'a';
            if (last == first && diff != 0) continue;    //  如果是入和出是相同的字符，那么跳过循环
            else if (last == first && diff == 0) {
                res.push_back(i - n + 1);
                continue;
            }
            //  判断右边界加入的字符
            if (cnt[last] == 0) diff++;     //  在last字符加入前判断其次数是否为0
            cnt[last]++;
            if (cnt[last] == 0) diff--;     //  在last字符加入后前判断其次数是否为0
            //  判断左边界减掉的字符
            if (cnt[first] == 0) diff++;  
            cnt[first]--;
            if (cnt[first] == 0) diff--;
            if (diff == 0) res.push_back(i - n + 1);
        }
        return res;
    }
};