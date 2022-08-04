class Solution {
    vector<vector<int>> memo;
public:
    //  返回s[i...]的子序列中t[j...]出现的次数
    int dp(string& s, string& t, int i, int j) {
        int n = t.size();
        int m = s.size();
        if (j == n) return 1;               //  当t[j..]为空串时，会在s[i...]的子序列中出现一次
        if (i == m) return 0;               //  当s[i...]为空串时，不存在能与t[j....]匹配的子序列
        if (memo[i][j] != -1) return memo[i][j];
        if (s[i] == t[j]) {                 //  当s[i] == t[j]时，我们可以选择是否让s[i]与t[j]匹配
        //  dp(s, t, i+1, j+1)代表让s[i]与t[j]匹配, 字符串指针同时后移; dp(s, t, i+1, j)代表不让s[i]与t[j]匹配， 
        //  返回s[i+1..]的子序列中能与t[j+1...]匹配的个数 (由于s[i]已经与t[j]匹配) + s[i+1..]的子序列能与t[j..]匹配的个数(s[i]不与t[j]匹配, i指针后移)
            return memo[i][j] = dp(s, t, i + 1, j + 1) + dp(s, t, i + 1, j);    
        } else {
            return memo[i][j] = dp(s, t, i + 1, j);                             // 返回s[i+1..]的子序列与t[j...]匹配的个数
        }       
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        memo.assign(n, vector<int>(m, -1));
        return dp(s, t, 0, 0);
    }
};