class Solution {
public:
    double QuickMul(double x, int n) {
        if (n == 0) return 1.0;
        double tmp = QuickMul(x, n / 2);
        if (n % 2 != 0) return tmp * tmp * x;
        else return tmp * tmp;
    }


    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) x = 1 / x, N = - N;
        return QuickMul(x, N);
    }
};