class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int m = n / 3;
        int p = 1000000007;
        long rem = 1;                       //  初始的余数为1 
        for (int i = 1; i < m ; i++) {       //  (x^a)%p = [(x^(a-1)%p) * (x%p)] %p = [(x^(a-1)%p)x] %p. a从1到m，我们这里的计算是从1到m-1, 因为当n%3 = 1时，我们需要把前面的3拆开变成2*2
            rem = (rem * 3) % p;   
        }     
        if (n % 3 == 0) return int(rem * 3 % p);
        if (n % 3 == 1) return int(rem * 4 % p);
        if (n % 3 == 2) return int(rem * 3 * 2 % p);
        return 0;
    }
};