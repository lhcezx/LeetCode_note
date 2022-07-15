//  回溯

class Solution {
public:
    //  对于每个子集我们需要的变量: k判断我们遍历到了哪个集合, target集合中的目标和, subset当前集合的元素和
    //  对于数字我们需要的变量: nums数字数组, visited记录遍历过的数字, start数字起点(前面放过的数字就不能重复放)
    bool backtrack(int k, int& target, int subset, vector<int>& nums, vector<bool>& visited, int start) {
        if (k == 0) return true;                                               //  当每个子集都被放入了数字且等于target
        if (subset == target) {
            return backtrack(k - 1, target, 0, nums, visited, 0);              //  将子集内元素和subset清零, start归零, 进入下一个子集。这里没有if判断，因为subset已经等于target了，再往subset里添加数字是没有意义的，所以只需要根据后面的k-1个桶是否被正确填满返回就可以，如果没有则会进入前一层的for循环重新选择当前桶的数字
        } 
        for (int i = start; i < nums.size(); i++) {
            if (subset + nums[i] > target || visited[i]) continue;
            visited[i] = true;
            subset += nums[i];
            if (backtrack(k, target, subset, nums, visited, i + 1)) return true;    //  只有当当前桶都正好凑满target的情况下，才会return true, 否则会不断尝试每个遍历过的元素
            visited[i] = false;
            subset -= nums[i];
        }

        //  遍历所有数字，都没法正好装满当前的桶
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0 || k > nums.size()) return false;                     //  元素总和不能被k整数, 或者集合数量大于元素数量
        int target = sum / k;
        vector<bool> visited(nums.size());
        sort(nums.begin(), nums.end());                                        //  升序排列
        if(nums[nums.size() - 1] > target) return false;                       //  存在比target大的数据，那么一定不能平分
        return backtrack(k, target, 0, nums, visited, 0);
    }
};