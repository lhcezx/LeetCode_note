class Solution {
public:
    int numWays(int n) {
        if (n == 0 || n == 1) return 1;
        if (n == 2) return 2;
        int fn_1 = 2, fn_2 = 1, mod = 1000000007, fn;   // 跳上一级台阶只有一种跳法，跳上两级台阶有两种跳法
        for (int i = 3; i <= n; ++i) {
            fn = (fn_1 + fn_2) % mod;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn ;
    }
};