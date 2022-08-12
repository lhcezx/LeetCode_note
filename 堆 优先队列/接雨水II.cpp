//  使用最小堆，最小堆的目的是从最矮的外面柱子开始计算其周边的格子能接的水为多少，然后依次更新所有格子

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int res = 0;
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        if (rows <= 2 || cols <= 2) return 0;
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //  遍历边缘，将其高度和一维坐标放入堆内
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                    int coord = i * cols + j;                               //  二维坐标转一维坐标
                    pq.emplace(heightMap[i][j], coord);
                    visited[i][j] = true;
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};      //  要遍历的四个方向
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            for (auto dir: dirs) {
                int nx = cur.second / cols + dir[0];
                int ny = cur.second % cols + dir[1];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny]) {
                    if (heightMap[nx][ny] < cur.first) {
                        res += cur.first - heightMap[nx][ny];
                        heightMap[nx][ny] = cur.first;                      //  更新heightMap[nx][ny]
                    }
                    visited[nx][ny] = true;
                    pq.emplace(heightMap[nx][ny], nx * cols + ny);
                }
            }
        }

        return res;
    }
};





