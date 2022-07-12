//  等同于找出所有子集大小等于2的不重复集合
class Solution {
    vector<vector<int>> res;
public:
    void backtrack(vector<int>& onPath, int start, int n, int k) {
        if (onPath.size() == k) {
            res.push_back(onPath);
            return;
        }
        for (int i = start; i <= n; i++) {
            onPath.push_back(i);
            backtrack(onPath, i + 1, n, k);
            onPath.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> onPath;
        backtrack(onPath, 1, n, k);
        return res;
    }
};