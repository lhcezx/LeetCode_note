class Solution {
    vector<vector<int>> res;
public:
    void traverse(vector<vector<int>>& graph, int s, vector<int>& path) {       //  s代表我们目前在的节点
        int n = graph.size();
        path.push_back(s);
        if (s == n - 1) {                                                       //  如果我们到达了最后一个节点，则说明我们获得了一条0到n的完整路径
            res.push_back(path);
            path.pop_back(); 
            return;
        }                                    
        for (int v: graph[s]) {                                                 //  遍历s元素的相邻节点
            traverse(graph, v, path);
        }
        path.pop_back();                                                        //  当我们要返回上层递归的时候，需要删除s，以便上层递归进入其他的路径
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        traverse(graph, 0, path);
        return res;
    }
};


class Solution {
    vector<int> onPath;
    vector<vector<int>> res;
public:
    void traverse(vector<vector<int>>& graph, int node) {
        if (node == graph.size() - 1) {
            res.emplace_back(onPath);
            return;
        }
        for (int neignbor: graph[node]) {
            onPath.push_back(neignbor);
            traverse(graph, neignbor);
            onPath.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        onPath.push_back(0);
        traverse(graph, 0);
        return res;
    }
};