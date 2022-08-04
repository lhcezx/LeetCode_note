//  核心思路: 统计n的阶乘中5的因子共有多少个. n的阶乘中每多乘一个10，零就会多一个. 由于10 = 2 x 5, 2的因子肯定比5多，因此转为统计5的因子共有多少个，就代表总共有多少个0

//  复杂度O(n)
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        //  遍历从0到n中所有5的倍数，计算每个倍数能够提供的5的因子
        for (int i = 5; i <= n; i += 5) {
            for (int k = i; k % 5 == 0; k /= 5) {
                count++;
            }
        }
        return count;
    }
};

//  复杂度O(logn)
//  ex: n = 125 -> 125 / 5 = 25, 代表有25个数由5这个因数构成，因此可以提供25个5. n /= 5 = 125 / 25 = 5, 代表由25作为因数提供的数字有5个, 最后125 / 125 = 1 = n /= 5 = 1，代表由125构成的因数有1个
//  5构成的数字能提供的因数至少为1，例如30，40. 由25作为因数能提供的5的因数为2，例如25, 50. 但由于刚才计算5的因数计算了一个，因此只需要将25构成的因数的数字加上即可，125为3个同理.
class Solution {
public:
    int trailingZeroes(int n) {
        int counter = 0;
        while (n) {
            n /= 5;
            counter += n;
        }
        return counter;
    }
};