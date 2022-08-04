//  埃氏筛

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, 1);
        int res = 0;
        //  遍历小于n的每一个数字
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                res += 1;
                if ((long long)i * i < n) {
                    //  如果某个数字i是质数，那么它的倍数2*i, 3*i.....一定不是质数 
                    for (int j = i * i; j < n; j += i) {    //  j从i*i开始而不是2*i开始，因为从2*i到i*i之间的数字已经被标记为非质数了
                        isPrime[j] = false;
                    }
                }

            }
        }
        return res;
    }
};