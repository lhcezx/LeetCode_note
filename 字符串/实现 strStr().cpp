//  有限状态机KMP

class KMP {
public: 
    vector<vector<int>> dp;                                 //  dp[i][j]意为当我们在状态i时遇到字符j，接下来要转移到的状态
    string pat;
    KMP(string& pat) {
        this->pat = pat;
        int n = pat.size();
        dp.assign(n, vector<int>(256, 0));
        dp[0][pat[0]] = 1;                                  //  当状态0遇到模式串的第一个字符的时候将状态转移到1，否则状态还是0
        int X = 0;                                          //  影子状态初始为0
        for (int i = 1; i < n; i++) {                       //  遍历每一个状态，我们找当状态i遇到字符c时，要转移到的状态
            for (int c = 0; c < 256; c++) {                 //  遍历ASCII码中的所有字符
                if (c == pat[i]) dp[i][c] = i + 1;          //  若与模式串的下一个字符匹配，则转移到下一个状态
                else dp[i][c] = dp[X][c];                   //  若不与模式串的下一个字符匹配，则转移到在影子状态遇到c字符时要转移的状态
            }
            X = dp[X][pat[i]];                              //  更新影子状态X为在前一个影子状态X遇到第i个模式串的字符时，要转移到的位置
        }
    }

    int search(string& txt) {
        int n = pat.size();
        int m = txt.size();
        int state = 0;                                      //  初始状态为0
        for (int i = 0; i < m ; i++) {
            state = dp[state][txt[i]];                      //  当我们在当前状态state，遇到txt[i]字符，应当转移到的状态
            if (state == n) return i - n + 1;               //  若状态转移到n，模式串在i索引位置与txt匹配完毕，返回匹配的初始字符位置
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        KMP* matcher = new KMP(needle);
        return matcher->search(haystack);
    }
};