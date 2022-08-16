//  回溯，超时
class Solution {
public:
    bool backtrack(string& s, vector<string>& wordDict, int i) {
        int n = s.length();
        if (i == n) return true;
        //  遍历字典中的每个单词，单词长度为len, 判断能否和子串s[i:i+len]匹配
        for (string word: wordDict) {
            int len = word.length();
            if (i + len <= n && s.substr(i, len) == word) {
                if (backtrack(s, wordDict, i + len)) return true;
            } 
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return backtrack(s, wordDict, 0);
    }
};

//  dp
//  dp[i]代表能否用字典中的单词组成s[0:i]这个子串，i需要从前面从0到i-1个状态中为true的状态转移，具体做法是将s[0:i]划分为s[0:j-1], s[j:i]两个串，s[0:j-1]就是dp[j]前面计算过，s[j:i]可以用哈希表中的单词查看是否有长度相等并且相匹配的单词。若s[0:j-1]为true, s[j:i]也能在字典中找到对应的单词，那么s[0:i]子串能被字典中单词匹配，dp[i]为true

class Solution {
    unordered_set<string> hash_set;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, 0);             //  dp[i]代表s的前i个字符能否用字典中若干单词组成
        dp[0] = true;                          //  base case, s为空串，不需要任何字符即可匹配
        for (auto word: wordDict) hash_set.insert(word);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {      
                if (dp[j] && hash_set.count(s.substr(j, i - j))) {      //  s.substr(j, i - j) = s[i, j) 左闭右开
                    dp[i] = true;
                    break;                     //  dp[i]一旦找到一个j分割点为true, 停止继续分割
                }
            }
        }
        return dp[n];
    }
};