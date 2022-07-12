//  组合的回溯问题，本质上每一次backtrack代表进入了组合的下一个位置，也就是说每个backtrack函数只管当前位置该放什么元素，通过for循环遍历每一个可能的元素，然后进入下一个位置(backtrack)重复同样的事情
//  由于不能包含重复的组合，因为组合是不需要有序的，所以我们先把数组排序让数组中相等的元素相邻。当我们在x位置时，for循环会遍历每一个在x位置出现的数字，当出现重复的情况，直接跳过

class Solution {
    vector<vector<int>> res;
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& onPath, int& sum, int start) {
        if (sum == target) {
            res.push_back(onPath);
            return;
        }
        if (sum > target) return;                                           //  当和大于target，直接返回到上层递归，pop掉最后一个元素并sum-=
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;  //  当在x位置要放的数字出现重复
            onPath.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, onPath, sum, i + 1);
            onPath.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> onPath;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, onPath, sum, 0);
        return res;
    }
};