//  计算出两个数组的每个位置的差，同时用另一个数组counter记录这些差出现的次数。然后用k1+k2次从最大的差开始--，动态减少最大的差。
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long res = 0;
        int n = nums1.size();
        vector<int> diff(n);
        vector<int> counter;
        int max_diff = 0;                                               //  用于后面初始化counter数组
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            max_diff = max(max_diff, diff[i]);
        }
        counter.assign(max_diff + 1, 0);                                //  从0到max_diff每个差出现的次数初始化为0, 最大的数组之差不会超过max_diff
        for (auto num: diff) {
            counter[num]++;                                             //  记录每个差值出现的次数
        }

        int k = k1 + k2;
        for (int i = max_diff; i > 0 && k > 0; i--) {                   //  从最大的差值向最小的差值遍历
            int change = min(k, counter[i]);                            
            counter[i - 1] += change;                                  
            counter[i] -= change;                                       
            k -= change;
        }
        for (int i = 0; i <= max_diff; i++) {
            res += pow(i, 2) * counter[i];
        }
        return res;
    }
};