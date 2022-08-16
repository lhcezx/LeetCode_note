//  回溯

class Solution {
    vector<string> res;
public:
    void backtrack(string& s, vector<string>& wordDict, int i, vector<string>& onPath) {
        int n = s.length();
        if (i == n) {
            string tmp = "";
            for (auto s: onPath) {
                tmp += (s + ' ');
            }
            tmp.pop_back();
            res.push_back(tmp);
        }
        //  对字典中的每个单词做选择
        for (string word: wordDict) {
            int len = word.length();
            //  如果单词和子串s[i, i+len-1]匹配，则按顺序记录进onPath
            if (i + len <= n && s.substr(i, len) == word) {
                onPath.push_back(word);
                backtrack(s, wordDict, i + len, onPath);
                onPath.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> onPath;
        backtrack(s, wordDict, 0, onPath);
        return res;
    }
};