//  本题的函数中的dp[i][j]数组的定义并不是从起始点grid[0][0]到dp[i][j]所需的最小血量，而是从dp[i][j]到终点grid[n - 1][m - 1]所需的最小血量。
//  解释: 正向DP的函数定义是从起点到grid[i][j]所需要的最小血量，当我们到达grid[i][j]以后可以选择向下或者向右进行状态转移，但我们由于只知道到grid[i][j]所需要的最小血量，但不知道走到grid[i][j]时的当前血量为多少，例如起始点grid[0][0] = -3，因此我们需要一个4点的起始血量，然后从grid[0][0]到grid[i][j]的路径上都是血瓶，因此所需的最小血量一直都是4，但是当grid[i][j]下一个位置会扣血，此时我们无法进行状态转移，即我们不知道需要最少多少血量才能通过扣血的格子，因为我们没有统计前面加的血有多少，所以也就不知道当前的血量是多少，也就是前面的路径和是没有统计的，所以无法进行状态转移。有人可能会想，那碰到血瓶就将需要的最小血量-grid[i][j]不就行了，但实际上是不行的，因为要通过grid[0][0]至少需要4点的血量，即使后面的血瓶再多，初始状态下都是拿不到的。

//  因此我们转换思路，考虑如果函数定义是从grid[i][j]走到终点grid[n][m]所需要的最小血量，这种情况我们在grid[i][j]可以轻易的判断，由于只能向右或者向下，因此我们只需要在grid[i][j]选择一条需要血量最小的路径就可以了，例如grid[i + 1][j] = 4, grid[i][j + 1] = 5, 我们必然会选grid[i + 1][j]这条路，然后对应的dp[i][j]结果等于min(dp[i - 1][j], dp[i][j - 1]) - grid[i][j]，当grid[i][j] < 0 时，代表会扣血，因此我们需要更多的血量才能保证从grid[i][j]走到终点，反之如果grid[i][j] > 0, 则我们需要更少的血量即可从grid[i][j]走到终点，需要注意的是血量至少为1，不可以小于等于0，因此当dp[i][j]最后的计算结果小于等于0时，我们需要将其归为1，剩余的血量实际上是多出来的一部分血量

//  正向dp是起点固定，我们在不停的转移终点的坐标; 反向dp是终点固定，我们一直在转移起点的坐标。正向dp我们只能计算从起点到grid[i][j]的最小血量，但无法推出到grid[i + 1][j]的最小血量，因为我们不知道当我们走到grid[i][j]时，剩余的血量是多少，因此无法判断后面的扣血是否会多扣，还是少扣; 反向dp我们能从grid[i][j]计算到终点的最小血量，我们可以推出从grid[i - 1][j]的到重点的最小血量，因为我们需要保证初始血量一定要大于等于1
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector<vector<int>> dp;                         //  dp[i][j]返回以[i, j]为起点到右下终点所需要的最小血量
        dp.assign(rows, vector<int> (cols));
        dp[rows - 1][cols - 1] = dungeon[rows - 1][cols - 1] >= 0 ? 1: abs(dungeon[rows - 1][cols - 1]) + 1;
        for (int i = rows - 1; i >= 0; i--) {           //  反向dp
            for (int j = cols - 1; j >= 0; j--) {
                if (i == rows - 1 && j == cols - 1) continue;
                int right = j + 1 < cols ? dp[i][j + 1] : INT_MAX;
                int down = i + 1 < rows ? dp[i + 1][j] : INT_MAX;
                int res = min(right, down) - dungeon[i][j];
                dp[i][j] = res > 0 ? res : 1;
            }
        }
        return dp[0][0];
    }
};