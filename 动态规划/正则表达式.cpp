class Solution {
    vector<vector<int>> memo;
public:
    //  函数返回s[i..]和p[j...]能否正确匹配
    bool dp(string& s, string& p, int i, int j) {
        int n = s.size();
        int m = p.size();
        if (j == m) return i == n;                                  //  当j指针走完整个p字符，判断i指针是否走完了整个s字符，若是则完成匹配
        if (i == n) {                                               //  当i字符串已经走完，判断p[j...]后面的字符串能否匹配空串，若要匹配空串，则必然以字符+'*'的形式出现
            if ((m - j) % 2 != 0) return false;                     //  如果p字符串从j开始不是2的倍数，那必然不构成字符+'*'的pair，返回false
            for (; j + 1 < m; j += 2) {
                if (p[j + 1] != '*') return false;
            }
            return true;
        }

        if (memo[i][j] != -1) return memo[i][j]; 
        //  当s[i]和p[j]字符相同或p[j] == "."时
        if (s[i] == p[j] || p[j] == '.') {
            //  若p[j + 1]为'*'，则p[j + 1]可以零次或多次用p[j]匹配s串内的字符
            if (j + 1 < m && p[j + 1] == '*') {                                 
            //  dp(s, p, i, j + 2)意为让p[j]与s[i]匹配0次，匹配0次等于删除p[j]当前字符串，j指针后移到j + 2，判断s[i...]与p[j+2...]能否匹配
            //  dp(s, p, i + 1, j)意为让p[j]再与s[i]进行匹配，即s[i]与p[j]匹配，但p[j]仍然可以继续使用用来匹配s[i+1], 判断s[i+1...]与p[j]能否匹配
                return memo[i][j] = dp(s, p, i, j + 2) || dp(s, p, i + 1, j);       //  当s[i]与p[j]相等的时候，如果在p[j + 1]为'*'的情况下有两种选择，要么匹配0次 dp(s, p, i, j + 2)，要么匹配多次，dp(s, p, i + 1, j)仅仅代表匹配了一次，但后面还可以继续匹配
            } else {
                return memo[i][j] = dp(s, p, i + 1, j + 1);                         // p[j + 1]不为'*'，常规匹配s[i], p[j]，然后分别后移指针
            }
        } else {
            if (j + 1 < m && p[j + 1] == '*') {
                return memo[i][j] = dp(s, p, i, j + 2);             //  p[j + 1]的'*'将p[j]匹配0次，结束后j移动到p[j + 2]的位置上，判断s[i]和p[j+2]
            } else {
                return memo[i][j] = false;
            }
        }    
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        memo.assign(n, vector<int>(m, -1));
        return dp(s, p, 0, 0);
    }
};