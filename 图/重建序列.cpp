//  借助BFS版拓扑排序，每次判断队列中入度为0的节点是否超过1，如果超过1则说明有至少2个节点可以作为起点(说明它们不连通)，则这两个子序列可以拥有不唯一的超序列. ex: {1, 2}, {3}可以构成{1, 2, 3}或{3, 1, 2}

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> indegree(n + 1);                //  节点数字从1到n;
        vector<vector<int>> graph(n + 1);
        queue<int> q;
        //  构建有向图
        for (auto sequence: sequences) {
            for (int i = 1; i < sequence.size(); i++) {
                int from = sequence[i - 1];
                int to = sequence[i];
                graph[from].push_back(to);
                indegree[to]++;  
            }
        }
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) q.push(i);        //  将入度为0的节点放入队列
        }
        while (!q.empty()) {
            if (q.size() > 1) return false;         //  当队列中节点超过1，说明入度为0的节点大于1
            int cur = q.front();
            q.pop();
            for (int neighbor: graph[cur]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }
        return true;
    }
};