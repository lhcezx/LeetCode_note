class NumArray {
    vector<int> pre_sum;
    vector<int>nums;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        this->nums = nums;
        for (int num: nums) {
            sum += num;
            pre_sum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return pre_sum[right] - pre_sum[left] + nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */