// DFS
class Solution {
    vector<bool> visited;
    vector<bool> color;                 //  true和false代表两种颜色
    bool ok = true;                     //  用于判断是不是二分图
public:
    void traverse(vector<vector<int>>& graph, int start) {
        if (!ok) return;                //  如果已经发现不是二分图了，则不需要后面的递归遍历节点
        visited[start] = true;
        for (int neignbor: graph[start]) {
            if (!visited[neignbor]) {
                color[neignbor] = !color[start];            //  如果该节点未被访问，则将该节点的颜色和start颜色相反
                traverse(graph, neignbor);
            } else {                                        //  如果该节点被访问过了，则需要判断节点邻居和该节点的颜色是否相同
                if (color[neignbor] == color[start]) ok = false;         //  如果两个相邻节点的颜色相同，则不是二分图
            }
            
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        visited.resize(graph.size());
        color.resize(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) traverse(graph, i);        //  如果该节点没被经过，则以该节点为起点遍历
        }
        return ok;
    }
};

// BFS
class Solution {
    vector<bool> visited;
    vector<bool> color;                 //  true和false代表两种颜色
    bool ok = true;                     //  用于判断是不是二分图
public:
    void bfs(vector<vector<int>>& graph, int start) {
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (ok && !q.empty()) {
            int node = q.front();                       //  启始节点
            q.pop();
            for (int neignbor: graph[node]) {           //  遍历启始节点的每一个邻居节点
                if (!visited[neignbor]) {
                    q.push(neignbor);                   //  将邻居节点压入队列
                    visited[neignbor] = true;
                    color[neignbor] = !color[node];     //  染色
                } else {
                    if (color[neignbor] == color[node]) ok = false;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        visited.resize(graph.size());
        color.resize(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) bfs(graph, i);        //  如果该节点没被经过，则以该节点为起点遍历
        }
        return ok;
    }
};