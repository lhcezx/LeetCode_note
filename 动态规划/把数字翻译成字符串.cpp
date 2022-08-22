class Solution {
public:
    int translateNum(int num) {
        string _num = to_string(num);
        int n = _num.size();
        if (n == 1) return 1;
        vector<int> dp(n);          //  dp[i]返回num[0:i]共有多少种翻译方法
        dp[0] = 1;  
        dp[1] = 1;
        if (_num.substr(0, 2) <= "25") dp[1] = 2;    
        for (int i = 2; i < n; i++) {
            string tmp = _num.substr(i - 1, 2);
            if (tmp >= "10" && tmp <= "25" ) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};