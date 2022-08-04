class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size(), cols = triangle[rows - 1].size();
        vector<vector<int>> dp(rows, vector<int>(cols));                                //  dp[i][j]返回自顶向下到达triangle[i][j]的最小路径
        dp[0][0] = triangle[0][0];                                                      //  base case
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int neighbor1 = j - 1 >= 0 ? dp[i - 1][j - 1] : INT_MAX / 2;            //  判断j-1位置的邻居是否存在，
                int neighbor2 = j < triangle[i - 1].size() ? dp[i - 1][j] : INT_MAX / 2;//  判断j位置在上一层是否存在
                dp[i][j] = min(neighbor1, neighbor2) + triangle[i][j];
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < cols; i++) {
            res = min(res, dp[rows - 1][i]);
        }
        return res;
    }
};