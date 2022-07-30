//  直接DP，会超时

class Solution {
    vector<vector<int>> memo;
public:
    //  返回我们在剩余k个鸡蛋时待搜索的楼层总数n，找到第f层最坏情况下的最小操作数
    int dp(int k, int n) {
        if (n == 0) return 0;               //  base case, 当需要搜索的楼层数为0时，操作数为0
        if (k == 1) return n;               //  如果只剩下一个鸡蛋了，那么需要线性搜索所有剩余的n个楼层，不要认为是f次操作，因为讨论的是最坏情况，若n == f的情况下，需要搜索n次
        if (memo[k][n] != -1) return memo[k][n];
        int res = INT_MAX;
        //  状态转移，从1-n层中的哪一层扔鸡蛋(注意这里的1-n非实际的1-n, 例如dp(k, n - i)中的1-n为从n-i到第n层，里面的n-i就是第一层)
        for (int i = 1; i <= n; i++) {
            //  dp(k - 1, i - 1)代表鸡蛋在第i层碎了，还剩下k-1个鸡蛋，和i-1个待搜索楼层; dp(k, n - i)代表鸡蛋在第i层没碎，剩下k个鸡蛋和n-i个待搜索楼层
            //  求max代表取蛋碎与不碎两种情况中的最坏的情况，因为我们不知道f具体在哪层，我们只能取最坏的情况
            int subProb = max(dp(k - 1, i - 1), dp(k, n - i)) + 1;      
            res = min(res, subProb);
        }
        return memo[k][n] = res;
    }

    int superEggDrop(int k, int n) {
        memo.assign(k + 1, vector<int>(n + 1, -1));
        return dp(k, n);
    }
};

// 二分 + DP

class Solution {
    vector<vector<int>> memo;
public:
    //  返回我们在剩余k个鸡蛋时待搜索的楼层总数n，找到第f层最坏情况下的最小操作数
    int dp(int k, int n) {
        if (n == 0) return 0;               //  base case, 当需要搜索的楼层数为0时，操作数为0
        if (k == 1) return n;               //  如果只剩下一个鸡蛋了，那么需要线性搜索所有剩余的n个楼层，不要认为是f次操作，因为讨论的是最坏情况，若n == f的情况下，需要搜索n次
        if (memo[k][n] != -1) return memo[k][n];
        int res = INT_MAX;

        // for (int i = 1; i <= n; i++) {
        //     int subProb = max(dp(k - 1, i - 1), dp(k, n - i)) + 1;      
        //     res = min(res, subProb);
        // }
        //  max(dp(k - 1, i - 1), dp(k, n - i)) + 1, 状态转移方程中我们可以看到K和N固定的情况下，dp(k - 1, i - 1)是关于i的单调递增函数(i越大需要搜索的楼层越多，最小操作数就越大), dp(k, n - i))是关于i的递减函数(i越大需要搜索的楼层越少，最小操作数就越小)，我们需要对两者求max后对每个i求min，这个min实际上就是两个单调函数的交点值, 因此可以用二分搜索思路，用logn的复杂度找到min
        int left = 1, right = n;            //  待搜索的楼层左边界和右边界
        while (left <= right) {
            int mid = left + (right - left) / 2;        //  我们在mid层扔鸡蛋
            int broken = dp(k - 1, mid - 1);
            int unbroken = dp(k, n - mid);
            if (broken >= unbroken) {                    //  如果broken操作数比unbroken大，broken是单增的unbroken是单减的，因此我们在交点右侧
                right = mid - 1;
                res = min(res, broken + 1);
            } else {                                    //  如果unbroken操作数比broken大，broken是单增的unbroken是单减的，因此我们在交点左侧
                left = mid + 1;
                res = min(res, unbroken + 1);
            }
        }
        return memo[k][n] = res;
    }

    int superEggDrop(int k, int n) {
        memo.assign(k + 1, vector<int>(n + 1, -1));
        return dp(k, n);
    }
};