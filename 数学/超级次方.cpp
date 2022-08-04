//   注意(ab) % k = (a % k * b % k) % k
int mod = 1337;
class Solution {
public:
    //  求a的n次幂对1337取模，快速幂算法
    long quickPow(int a, int n) {
        if (n == 0) return 1;
        long tmp = quickPow(a, n / 2);
        long res = (tmp % mod * tmp % mod) % mod;                // tmp^2 % mod = (tmp % mod * tmp % mod) % mod
        if (n % 2 == 0) return res;
        else return (res % mod * a % mod) % mod;
    }

    //  返回a的vectorb次方对1337取模的结果
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last = b.back();
        b.pop_back();  
        // ex: 2^1357 = 2^7 * (2^135)^10 
        int part1 = quickPow(a, last);                          //  返回对a^last次方取模的结果
        int part2 = quickPow(superPow(a, b), 10);               //  返回对superPow(a, b)^10取模的结果
        return part1 * part2 % mod;                             //  最后需要将两个乘积再次取模     
    }
};