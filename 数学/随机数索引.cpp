class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums.assign(nums.begin(), nums.end());
    }
    
    int pick(int target) {
        int counter = 0;
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target) continue; 
            counter++;
            if (rand() % counter == 0) res = i;
        }
        return res;
    }
};