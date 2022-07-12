//  子集属于组合问题，当我们在某个位置x时，我们可以选择nums[x]到nums.back()的所有元素放在x位置

class Solution {
    vector<vector<int>> res;
public:
    void backtrack(vector<int>& nums, vector<int>& onPath, int start) {
        res.push_back(onPath);
        for (int i = start; i < nums.size(); i++) {
            onPath.push_back(nums[i]);
            backtrack(nums, onPath, i + 1);
            onPath.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> onPath;
        backtrack(nums, onPath, 0);
        return res;
    }
};