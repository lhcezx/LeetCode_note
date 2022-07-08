class Solution {
public:
    int splite(vector<int>& nums, int sum) {        //  sum为我们想要子数组和不超过的值，也就是子数组和的上限
        int m = 0;                                  //  我们为了不超过该数组上线，所需要分割的次数
        for (int i = 0; i < nums.size();){
            int tmp_sum = sum;
            while (i < nums.size()){
                if (nums[i] > tmp_sum) break;
                tmp_sum -= nums[i];
                i++;
            }
            m++;
        }
        return m;
    }

    int splitArray(vector<int>& nums, int m) {
        int left = 0, right = 0;         //  二分查找的左边界和右边界
        for (int num: nums) {
            left = max(left, num);       //  左边界为nums中的最大值, 否则将无法分割数组
            right += num;                //  右边界为整个数组的元素和
        }
        while (left <= right) {
            int mid = left + (right - left) / 2; 
            if (splite(nums, mid) > m) left = mid + 1;               //  分割的次数比要求次数多，说明子数组最大和太低了
            else right = mid - 1;
        }
        return left;
    }
};