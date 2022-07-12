class Solution {
    vector<vector<int>> res;
public:
    void backtrack(vector<int>& candidates, vector<int>& onPath, int target, int& sum, int start) {
        if (sum == target) {
            res.push_back(onPath);
        }
        if (sum > target) return;
        for (int i = start; i < candidates.size(); i++) {
            onPath.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, onPath, target, sum, i);          //  注意这里不是i+1, 而是i
            sum -= candidates[i];
            onPath.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> onPath;
        int sum = 0;
        backtrack(candidates, onPath, target, sum, 0);
        return res;
    }
};