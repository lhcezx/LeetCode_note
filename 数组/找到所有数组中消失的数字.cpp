//  将每个nums[i]看作索引，用来访问数组中的元素, 具体的我们这样做nums[nums[i] - 1]. 由于1<=nums[i]<=n, 减一让它偏移到[0,n]
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        //  将nums中的数字全部看作索引，将所有元素改为负，缺失的那些元素的索引一定为正
        for (int num: nums) {
            if (nums[abs(num) - 1] > 0) {
                nums[abs(num) - 1] *= -1;            
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};