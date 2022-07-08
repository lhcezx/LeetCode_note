class Solution {
    vector<bool> visited;
    vector<bool> color;
    bool ok = true;
public:
    //  构建无向图
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        for (vector<int> pair: dislikes) {
            graph[pair[1] - 1].push_back(pair[0] - 1);          //  -1的目的是让数字从[1, n]变为从[0, n)
            graph[pair[0] - 1].push_back(pair[1] - 1);
        }
        return graph;
    }

    //  两两互相不喜欢，说明相邻两个节点分在不同的组，也就是他们的颜色不同。如果能完成二分图的构建，那么说明可以将他们分为两组
    void traverse(vector<vector<int>>& graph, int start) {
        if (!ok) return;
        visited[start] = true;
        for (int neignbor: graph[start]) {
            if (!visited[neignbor]) {
                color[neignbor] = !color[start];
                traverse(graph, neignbor);
            } else {
                if (color[neignbor] == color[start]) ok = false;
            }
        }
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph;
        visited.resize(n);
        color.resize(n);
        graph = buildGraph(n, dislikes);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) traverse(graph, i);
        }
        return ok;
    }
};