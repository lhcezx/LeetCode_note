class UnionFind{
    vector<int> parent;
public:
    int count = 0;
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;          //  将每个节点初始化为根节点
        }
    }

    void Union(int i, int j) {
        int root_i = Find(i);
        int root_j = Find(j);
        if (root_i == root_j) return;
        parent[root_i] = root_j;
        count--;
    }

    int Find(int i) {
        if (parent[i] != i) {
            parent[i] = Find(parent[i]);
        }
        return parent[i];
    }

    bool connected(int i, int j) {      //  判断i, j是否在一个集合里
        return Find(i) == Find(j);
    }

};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind* UF = new UnionFind(26);          //  总共26个小写字母
        for (auto equation: equations) {
            if (equation[1] == '=') UF->Union(equation[0] - 'a', equation[3] - 'a');        //  如果有 == 条件，则说明两个值相等，因此我们将它连通起来，同时将其他和它相等的值全部连通
        }
        for (auto equation: equations) {
            if (equation[1] == '!') {
                if (UF->connected(equation[0] - 'a', equation[3] - 'a')) return false;      //  如果两个必然不相等的变量i, j被连通了，则说明他们存在==判别式
            }
        }
        return true;
    }
};