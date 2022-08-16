//  将nums数组分为numsA, numsB, numsC三个子数组，题目寻找最短无序子数组，也就是要numsB最短，也就是numsA和numsC最长。核心思路是将整个nums排序，排序后的numsA和numsC不变，只有numsB改变了，因此用双指针从左向右和从右向左分别找到第一个不相同的数字即可。 如何能保证这种方法numsB是最短的呢？实际上当我们用双指针从两边开始找第一个不相同的数字时，就已经将numsB缩到了最短

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums(nums);
        if (is_sorted(nums.begin(), nums.end())) return 0;          //  判断数组是否有序，若有序直接返回0
        sort(sorted_nums.begin(), sorted_nums.end());
        int left = 0, right = nums.size() - 1;
        while (nums[left] == sorted_nums[left]) left++;              
        while (nums[right] == sorted_nums[right]) right--;
        return right - left + 1;
    }
};


//  一次遍历

//  将nums数组分为numsA, numsB, numC. numsB为最短无序连续子数组，我们需要动态维护numsB中的最大值_max和最小值_min. 一个索引下标begin和end.
//  _max的目的是通过保存numsB中的最大值来找到numsB的结尾索引end, _min的目的是通过保存numsB中的最小值来找到numsB的开头索引begin.
//  numsA中的所有数字一定比_min小，numsC中所有的数字一定比_max大.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int begin = 0, end = 0;
        int n = nums.size();
        int _max = INT_MIN, _min = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < _max ) {                          //  如果nums[i]比我们保存的_max要小，那么nums[i]一定不是numsC中的数字，所以后移end至i
                end = i;
            } else {                                        //  若比max大，则更新max的值
                _max = nums[i];
            }
            if (nums[n - i - 1] > _min) {                   //  若nums[n - i - 1]比我们保存的_min大，那么nums[i]一定不在numsA中，因此begin前移
                begin = n - i - 1;
            } else {
                _min = nums[n - i - 1];                     //  若比它小则更新nums[n - i - 1]
            }
        }
        return end == 0 ? 0 : end - begin + 1;
    }
};