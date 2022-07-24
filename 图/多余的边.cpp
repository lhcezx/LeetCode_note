//  启始状态下所有节点都是单独的连通分量，都在各自的集合中，如果遍历到两个节点在相同的集合中，说明是形成了回环，并且是edges 中最后出现的边
class UnionFind {
public:
    int count;
    vector<int> parent;
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void Union(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i == root_j) return;
        parent[root_i] = root_j;
        count--;
    }

    int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> res;
        UnionFind* UF = new UnionFind(n);
        for (auto edge: edges) {
            int from = edge[0] - 1;
            int to = edge[1] - 1;
            if (!UF->connected(from, to)) UF->Union(from, to);
            else {
                res.push_back(from + 1);                //  若两个节点已经在同一个集合，代表存在回环
                res.push_back(to + 1);
            }
        }
        return res;
    }
};