//  未优化版
class Solution {

public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp_table(nums.size(), INT_MIN);                   //  以i指针为数组尾指针的子数组的最大和
        dp_table[0] = nums[0];                                        //  base case
        for (int i = 1; i < dp_table.size(); i++) {
            dp_table[i] = max(dp_table[i - 1] + nums[i], nums[i]);    //  以i-1结尾的数组的最大和加当前nums[i]或当前nums[i]本身
        }
        int res = INT_MIN;
        for (int i = 0; i < dp_table.size(); i++) {
            res = max(res, dp_table[i]);
        }
        return res;
    }
};

//  优化版

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];                                           
        int dp_i_1 = nums[0];                        //  base case 
        int dp_i = 0;      
        for (int i = 1; i < nums.size(); i++) {
            dp_i = max(dp_i_1 + nums[i], nums[i]);    //  以i-1结尾的数组的最大和加当前nums[i]或当前nums[i]本身
            dp_i_1 = dp_i;
            res = max(res, dp_i);
        }
        return res;
    }
};