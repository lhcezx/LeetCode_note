class unionFind {
public:
    int counter;                                //  统计连通分量
    vector<int> parent;                         //  记录每个节点所在的连通分量的根节点
    unionFind (int n) {
        counter = n;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);                //  启始状态下，每个节点是一个独立的连通分量，根节点为自身
        }
    }

    void Union(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i == root_j) return;
        // root_i = parent[root_j];
        parent[root_i] = root_j;
        counter--;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unionFind* UF = new unionFind(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    UF->Union(i, j);
                }
            }
        }
        return UF->counter;
    }
};