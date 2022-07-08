class Solution {
//  不重复的交换方法总数为n*(n-1)*(n-2)*.....*1
public:
    vector<string> res;
    // pos代表我们当前在字符串的位置
    void dfs(string s, int pos) {
        if (pos == s.length() - 1) {                // 当我们到达字符串的最后一位的时候，这一位只有一种可能性，因此不需要交换
            res.push_back(s);
            return;
        }           
        unordered_set<char> set;
        for (int i = pos; i < s.size(); i++) {      // i会从pos位置开始遍历pos后的每一个字符
            if (set.find(s[i]) != set.end()) continue;       //  若pos固定位的字符串已经出现过，即s[i]位置上找到了相同的字符，则不需要交换，避免重复字符
            set.insert(s[i]);
            swap(s[i], s[pos]);                     // 将pos这个固定的位置字符逐步和后面的每一个字符进行交换
            dfs(s, pos + 1);                        // 递归从字符串的头到尾每一个固定的位置
            swap(s[i], s[pos]);                     // 需要将前面的swap交换的字符恢复原本的位置，因为这里用的for循环是为了遍历原始字符串的每一位，所以需要保证字符串恢复初始状态
        }
    }
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }
};