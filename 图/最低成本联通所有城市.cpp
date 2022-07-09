// Kruskal最小生成树算法，并查集 + 贪心

class UnionFind {
    vector<int> parent;
public:
    int count;
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void Union(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i == root_j) return;
        parent[root_i] = root_j;
        count--;
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    int cost = 0;
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        UnionFind* UF = new UnionFind(n);
        sort(connections.begin(), connections.end(), compare);              // 将每一条边的权重从小到大排列
        for (auto connection: connections) {
            if (UF->count == 1) break;                                      //  当连通分量为1时，说明我们找到了一条无环并且能连接所有城市的路径
            if (UF->connected(connection[0] - 1, connection[1] - 1)) continue;      //  如果边的两个节点已经在同一个子集，则不再创建边，防止成环
            UF->Union(connection[0] - 1, connection[1] - 1);                //  -1的原因是城市编号为[1, n], 我们的下标是[0, n);
            cost += connection[2];
        }
        return UF->count == 1? cost: -1;
    }
};