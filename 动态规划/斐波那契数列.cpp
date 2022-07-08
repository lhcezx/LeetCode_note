class Solution {
public:
    int fib(int n) {
        if (n == 0) {return 0;}
        int fn = 1, fn_1 = 1, fn_2 = 0;
        for (int i = 2; i <= n; ++i) {
            fn = fn_1%1000000007 + fn_2%1000000007;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn%1000000007;
    }
};