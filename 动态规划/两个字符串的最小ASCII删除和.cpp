//  换句话说，这个题目求的是，s1和s2的公共子序列中ascii码最大的子序列
class Solution {
    vector<vector<int>> memo;
public:
    //  返回使s1[0:i], s2[0:j]相等所需删除的ASCII值 
    int dp(string& s1, string& s2, int i, int j) {
        //  三个base case: i, j都遍历结束; i提前遍历结束; j提前遍历结束
        if (i < 0 && j < 0) return 0;
        //  当i遍历完s1时，需要把s2[0, j]部分删除
        if (i < 0) {                            
            int sum = 0;
            for (int k = 0; k <= j; k++) {
                sum += s2[k];
            }
            return sum;
        }
        //  当i遍历完s1时，需要把s1[0, i]部分删除
        if (j < 0) {                            
            int sum = 0;
            for (int k = 0; k <= i; k++) {
                sum += s1[k];
            }
            return sum;
        }
        if(memo[i][j] != -1) return memo[i][j];
        if (s1[i] == s2[j]) return memo[i][j] = dp(s1, s2, i - 1, j - 1);
        else return memo[i][j] = min(dp(s1, s2, i - 1, j) + s1[i], dp(s1, s2, i, j - 1) + s2[j]);
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        memo.assign(n, vector<int> (m, -1));
        return dp(s1, s2, n - 1, m - 1);
        
    }
};
};