//  j - i != nums[j] - nums[i]可以转变为 j - nums[j] != i - nums[i] 且 i < j, 因此只需要从前向后记录所有的nums[i] - i出现的次数即可
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long total = (long long)n * (long long)(n - 1) / 2;              //  总的数对的个数
        long long cnt = 0;
        for (int i = 0; i < nums.size(); i++) {                      //  顺序遍历保证了 i < j
            cnt += mp[i - nums[i]];                                  //  统计好数对的个数
            mp[i - nums[i]]++;                                       //  将mp++放在后面，代表第一次出现数字的时候不统计，从第二次开始出现数对才才开始统计
        }
        return total - cnt;
    }
};