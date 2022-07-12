//  排列问题，当我们在位置x的时候，我们可以选择nums中所有的元素放在x位置，但我们需要保证我们当前位置选择的元素在其他位置没有被选，因此需要visited数组来记录当前排列已经选择的数字都有哪些

class Solution {
    vector<vector<int>> res;
public:
    void backtrack(vector<int>& nums, vector<int>& onPath, vector<bool>& visited) {
        if (onPath.size() == nums.size()) res.push_back(onPath);
        for (int i = 0; i < nums.size(); i++) { //  在某个x位置上(取决于我们在哪一层递归), 我们可以选择数组中所有元素放在该位置用作排列
            if (visited[i]) continue;           //  如果数组中的i位置的元素已经被选用了，那么我们不能重复使用该元素
            onPath.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, onPath, visited);
            onPath.pop_back();                  //  回溯返回到上层时，将前面push_back进来的nums[i]弹出
            visited[i] = false;                 //  进入下一次for循环，修改当前visited标记
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> onPath;
        vector<bool> visited(nums.size());
        backtrack(nums, onPath, visited);
        return res;
    }
};