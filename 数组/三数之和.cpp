class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;            //  同样的数字选过了不在选，去重
            int target = 0 - nums[i];                               //  固定一个数字后选另另外两个
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] > target) right--;
                else if (nums[left] + nums[right] < target) left++;
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    //  去重操作
                    while (left < right && nums[left - 1] == nums[left]) left++;
                    while (left < right && nums[right + 1] == nums[right]) right--;
                }
            }
        }
        return res;
    }
};