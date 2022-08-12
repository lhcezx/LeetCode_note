class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;                       // 去重
            for (int j = i + 1; j < nums.size(); j++) { 
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;               // 去重
                long x = (long)target - (long)nums[i] - (long)nums[j];                             //  固定另外两个数字后选另外两个           
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    if (nums[left] + nums[right] > x) right--;
                    else if (nums[left] + nums[right] < x) left++;
                    else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        //  去重操作
                        while (left < right && nums[left - 1] == nums[left]) left++;
                        while (left < right && nums[right + 1] == nums[right]) right--;
                    }
                }
            }
        }
        return res;
    }
};
