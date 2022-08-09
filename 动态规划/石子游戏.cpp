// 详细细节见预测赢家.cpp

// 区间dp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp;                     //  dp[i][j]代表piles可选的范围为piles[i, j]时，先手玩家所能获得的最大净分数
        int n = piles.size();
        dp.assign(n, vector<int> (n));
        // base case
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};



// 状态压缩版
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n);                     //  dp[i][j]代表piles可选的范围为piles[i, j]时，先手玩家所能获得的最大净分数
        // base case
        for (int i = 0; i < n; i++) {
            dp[i] = piles[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                //  dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);  
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] > 0;
    }
};


//  数学版
//  按照石头堆的索引可以分为奇数堆和偶数堆，奇数堆为1, 3, 5, 7...，偶数堆为0, 2, 4, 6...，两堆的数量相同，但石子总数不同。由于是先手，我们如果想要选择偶数堆就拿最左边的那个，如果想要选择奇数堆就先拿最后边那个
//  例如我们选择了最左边的0，也就是选了偶数堆，后手只能选择1或者最后的那个，这两种选择都是奇数堆; 同理如果选择最后一个n - 1, 则对手只能选0或n - 2,都为偶数堆，因此先手可以选择更大的堆(奇偶).
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
