class UnionFind {
public:
    int count;
    vector<int> parent;
    UnionFind(int n) {
        count = n;
        parent.assign(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void Union(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i == root_j) return;
        parent[root_i] = root_j;
        count--;        //  不要忘记将连通分量--
    }

    int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);            //  递归直到根节点
        return parent[i];
    }
};

class Solution {
public:
    bool check(string& s1, string& s2) {
        int counter = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) counter++;
        }
        return counter > 2 ? false: true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind* UF = new UnionFind(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(strs[i], strs[j])) UF->Union(i, j);
            }
        }
        return UF->count;
    }
};