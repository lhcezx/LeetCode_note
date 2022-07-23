class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, string& s, char dir) {        //  dir用来记录用来序列化的方向
        int rows = grid.size();
        int cols = grid[0].size();
        if (i >= rows || i < 0 || j >= cols || j < 0) return;
        if (grid[i][j] == 0) return;
        grid[i][j] = 0;                                 // 将岛屿淹没
        s.push_back(dir);                               // 当我们走到陆地的时候，序列化岛屿
        //  用1, 2, 3, 4表示上下左右，-1, -2, -3, -4表示撤回，以此方式来序列化一个岛屿
        //  撤销操作的存在是为了保证岛屿的唯一性，例如[[11],[10]]和 [[10],[11]]两个不同的岛屿，但如果没有撤销操作，则它们是相同的序列化，都是[2, 4]
        dfs(grid, i - 1, j, s, '1');                
        dfs(grid, i + 1, j, s, '2');
        dfs(grid, i, j - 1, s, '3');
        dfs(grid, i, j + 1, s, '4');
        s.push_back(-dir);                              //  离开时序列化撤销操作
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> hash_set;                 //  用哈希集合记录所有的不同的序列化种类
        string tmp = "";
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    tmp = "";
                    dfs(grid, i, j, tmp, 'x');          //  岛屿的序列化用x初始化
                }
                if (!tmp.empty()) hash_set.insert(tmp);
            }
        }
        return hash_set.size();
    }
};