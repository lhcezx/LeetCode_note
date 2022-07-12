class Solution {
    vector<vector<int>> res;
public:
    void backtrack(vector<int>& nums, int start, vector<int>& onPath) {
        res.push_back(onPath);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;      //  避免在组合的某个位置放入相同的元素
            onPath.push_back(nums[i]);
            backtrack(nums, i + 1, onPath);
            onPath.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> onPath;
        backtrack(nums, 0, onPath);
        return res;
    }
};