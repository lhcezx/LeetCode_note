class unionFind {
    vector<int> parent;
public:
    int count;
    unionFind(int n) {
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
    bool validTree(int n, vector<vector<int>>& edges) {
        unionFind* UF = new unionFind(n);
        for (vector<int> edge: edges) {
            //  如果两个节点已经存在于同一个集合中 (连接着同一个子树的子节点)，我们仍然要再将它们连起来，那么就会构成一个环
            if (UF->connected(edge[0], edge[1])) return false;   
            UF->Union(edge[0], edge[1]);    //  如果还没存在于同一个集合，那么就将他们放入同一个集合
        }
        return UF->count == 1;              //  必须是只有一个联通分量，也就是所有的节点连接着同一个根节点，只有一棵树
    }
};