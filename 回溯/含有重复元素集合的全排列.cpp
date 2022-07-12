// 标准全排列算法之所以出现重复，是因为把相同元素形成的排列序列视为不同的序列，但实际上它们应该是相同的；而如果固定相同元素形成的序列顺序，当然就避免了重复。

class Solution {
    vector<vector<int>> res;
public:
    void backtrack(vector<int>& nums, vector<int>& onPath, vector<bool>& visited) {
        if (onPath.size() == nums.size()) {
            res.push_back(onPath);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            //  如果当前元素和前一个相同，则跳过，避免在同一个位置出现相同的数字。
            //  但会出现位置x+1取到的元素等于位置x取到的元素nums[x+1] = nums[x]，这时我们是在执行正常的排列，如果不加任何条件，那么这个x+1位置的这个元素会被跳过。ex: [1, 2, 2]
            //  因此我们需要标记如果i-1位置的元素被visited了，那么说明我们在做每个位置独立的排列问题，不能被跳过
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) continue;      
            onPath.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, onPath, visited);
            visited[i] = false;
            onPath.pop_back();
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> onPath;
        vector<bool> visited(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, onPath, visited);
        return res;
    }
};