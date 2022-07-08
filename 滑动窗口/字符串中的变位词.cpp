class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26);
        int n = s1.length(), m = s2.length();
        if (n > m) return false;
        for (int i = 0; i < n; i++) {
            cnt[s1[i] - 'a']--;                 //  当s1中这个字符出现的时候，次数--
            cnt[s2[i] - 'a']++;                 //  当s2中这个字符出现的时候，次数++
        }
        int diff = 0;                           //  用于统计s1和s2两个字符串中的出现的次数不一样的字符有多少个
        for (int x: cnt) {                      //  遍历每一个字符出现的次数
            if (x != 0) diff++;                //  当某个字符的次数不为0时，说明s1和s2中的这个字符出现的次数不一致
        }
        if (diff == 0) return true; 
        for (int i = n; i < m; i++) {           //  窗口开始滑动
            int last = s2[i] - 'a', first = s2[i - n] - 'a';
            if (first == last) continue;        //  如果窗口滑动的时候加入的元素等于删除的元素，则字符出现次数没有改变
            
            //  滑窗右边界last
            if (cnt[last] == 0) diff++;         //  如果加入的字符last原本出现的次数为0，由于加入该字符导致s1, s2该字符数量不统一，diff++
            cnt[last]++;
            if (cnt[last] == 0) diff--;         //  如果加入last字符后让出现的次数变为0，则s1和s2中last数量相同，diff--

            //  滑窗左边界first
            if (cnt[first] == 0) diff++;
            cnt[first]--;
            if (cnt[first] == 0) diff--;

            if (diff == 0) return true;
        }
        return false;
    }
};

// 哈希表做法

class Solution {
public:
    //  如果是变位词，那么两字符串s1和字符串s2的某个连续子串中字符出现的次数应当相同
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) return false;
        vector<int> cnt1(26), cnt2(26);         //  分别用来统计s1和s2中每个字符出现的次数
        for (int i = 0; i < n; i++) {
            cnt1[s1[i] - 'a']++;                //  按照s1的长度循环，记录s1字串中字符出现的次数 
            cnt2[s2[i] - 'a']++;                //  记录s2中从0开始到si长度的字串的字符出现次数
        }
        if (cnt1 == cnt2) return true;
        for (int i = n; i < m; i++) {
            cnt2[s2[i] - 'a']++;                //  滑动窗口，右边界加入新元素
            cnt2[s2[i - n] - 'a']--;            //  左边界减掉串首元素
            if (cnt1 == cnt2) return true;
        }
        return false;
    }
};