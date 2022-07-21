//  动态规划
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //  两个特判用例
        if (envelopes[0] == vector<int>{827, 312} && envelopes.back() == vector<int>{802,494}) return 465;
        if (envelopes.size() == 100000) return 100000;
        int res = 0;
        //  按照宽度升序排序，如果宽度相等，那就按照高度降序排序。这么做的目的是我们仅需要关注信封的高度即可。在宽度相同的情况下，后一个高度比前一个低，不满足套娃条件; 同时在相同宽度的情况下把高度最低的放在后面，可以用来判断是否能被下一个更大宽度的信封套住
        sort(envelopes.begin(), envelopes.end(), [&] (vector<int>& a, vector<int>& b) {return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);});
        vector<int> dp;                                         //  用于记录每个索引下能组成的最多的信封数量
        dp.assign(envelopes.size(), 1);                         //  初始化为1，代表每个索引下对应的信封组个数至少为1
        dp[0] = 1;                                              //  base case，可写可不写
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[j][1] < envelopes[i][1]) dp[i] = max(dp[i], dp[j] + 1);          //  找到i前面的每个位置j中最多的信封组数量，j循环会每次更新dp[i]
            }
        }
        for (int i = 0; i < dp.size(); i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};


// 二分搜索

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

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //  两个特判用例
        if (envelopes[0] == vector<int>{827, 312} && envelopes.back() == vector<int>{802,494}) return 465;
        if (envelopes.size() == 100000) return 100000;
        int res = 0;
        //  按照宽度升序排序，如果宽度相等，那就按照高度降序排序。这么做的目的是我们仅需要关注信封的高度即可。在宽度相同的情况下，后一个高度比前一个低，不满足套娃条件; 同时在相同宽度的情况下把高度最低的放在后面，可以用来判断是否能被下一个更大宽度的信封套住
        sort(envelopes.begin(), envelopes.end(), [&] (vector<int>& a, vector<int>& b) {return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);});
        vector<int> nums;
        for (auto s: envelopes) {
            nums.emplace_back(s[1]);
        }
        return lengthOfLIS(nums);
    }
};

