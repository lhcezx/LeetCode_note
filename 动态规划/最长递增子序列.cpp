// 动态规划

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp_table(nums.size());               //  记录每个索引下对应的最长严格递增子序列的长度
        dp_table[0] = 1;                                 //  base case
        for (int i = 1; i < nums.size(); i++) {          //  遍历每一个值i
            int sub_sequence = 0;
            for (int j = 0; j < i; j++) {                //  查看每一个值i前面的子序列中结尾的数小于nums[i]的子序列长度，找到其中最大的子序列, 由于nums[i] > nums[j]所以可以构成一个新的长度+1的子序列
                if (nums[j] < nums[i]) sub_sequence = max(sub_sequence, dp_table[j]);
            }
            dp_table[i] = sub_sequence + 1;
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = max(res, dp_table[i]);
        }
        return res;
    }
};


//  二分搜索

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> piles(nums.size());
        int piles_count = 0;                            //  这里的piles_count，相当于二分搜索中的nums.size()
        for (int i = 0; i < nums.size(); i++) {
            int poke = nums[i];                         //  查看每一张牌，决定将其放在哪个堆顶
            int left = 0, right = piles_count - 1;      //  左边界为0，右边界为已经创建的堆的数量-1 (类似二分搜索中的nums.size() - 1)
            //  左边界查找二分，因为如果有多个符合的堆，我们将其放到最左边的顶上。注意这里的piles堆顶元素是有序的，同时我们只保存堆顶元素
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (piles[mid] >= poke) right = mid - 1;
                else if (piles[mid] < poke) left = mid + 1;
            }
            if (left == piles_count) piles_count++;     //  如果没有找到合适的堆，left会一直移动到边界外也就是piles_count(nums.size()), 此时创建一个新的堆
            piles[left] = poke;
        }
        return piles_count;
    }
};
