class Solution {
    vector<vector<int>> res;
public:
    void backtrack(int k, int target, int& sum, vector<int>& onPath, int start) {
        if (sum == target && onPath.size() == k) {
            res.push_back(onPath);
            return;
        }

        if (sum > target || onPath.size() > k) return;
        for (int i = start; i <= 9; i++) {
            onPath.push_back(i);
            sum += i;
            backtrack(k, target, sum, onPath, i + 1);
            sum -= i;
            onPath.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = 0;
        vector<int> onPath;
        backtrack(k, n, sum, onPath, 1);
        return res;
    }
};