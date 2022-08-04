//  本题核心思路，一个包含[1, n]n个数的数组，索引为[0, n-1]. 遍历数组中的每一个数字nums[i]，并将其减一nums[i] - 1看作索引，由于数组中有重复的数字，那么我们一定会遍历两次相同的索引，也就是得到两次相同的nums[nums[i] - 1]. 我们每次遍历时，将nums[nums[i] - 1]设置为负号代表遍历过，如果遍历到的某个nums[nums[i] - 1]为负，则说明重复

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        //  找重复的数字
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;                  //  由于数组中的数字是[1,n], 我们希望数字是[0, n-1]. 注意这里需要加abs, 因为访问过的元素会被变为负数
            if (nums[idx] < 0) res.push_back(idx + 1);
            else nums[idx] *= -1;                     //  将其变为负数，代表遍历过
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
                break;
            }
        }
        return res;
    }
};