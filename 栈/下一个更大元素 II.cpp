class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> stk;
        //  环形数组通常我们会将数组长度翻倍，我们无需构建新的数组，只需要遍历两边即可。 
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i % n] >= stk.top()) stk.pop();
            res[i % n] = stk.empty()? -1: stk.top();
            stk.push(nums[i % n]);
        }
        return res;
    }
};