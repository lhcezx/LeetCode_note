//  O(nlongn)
class Solution {
public:
    int count1(int n) {
        int counter = 0;
        while (n > 0) {
            n &= (n - 1);               //  n &= (n - 1)能够消除n最右边的1
            counter++;
        }
        return counter;
    }

    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            res.push_back(count1(i));
        }
        return res;
    }
};

// O(n) 动态规划

//  动态维护最高有效位，二进制数字的最高有效位即它最左边的一保留，其他位全部为0
class Solution {
public:
    vector<int> countBits(int n) {
        int highbit = 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;                                          //  dp[i]返回数字i的二进制中1的个数1
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) highbit = i;            //  动态维护最高有效位
            dp[i] = dp[i - highbit] + 1;                    //  i = 100101, highbit = 100000, i - highbit = 00101;
        }
        return dp;
    }
};