class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int slow = 0, fast = 0, res = 0;
        int dot = 1;
        while (fast < nums.size()) {
            dot *= nums[fast];
            while (dot >= k && slow <= fast) {  //  这里判断条件中有slow <= fast而非单纯的<, 因为当dot >= k的时候，我们会让slow一直前进到fast+1的位置，使得后面的计算公式fast-slow+1等于0，避免误算
                dot /= nums[slow];
                slow++;
            }
            res += fast - slow + 1;             //  这里的公式计算出当slow和fast之间数字乘积和小于k时，slow和fast两个指针之间包含nums[fast]元素的连续子数组的数量。
            fast++;
            
        }
        return res;
    }
};