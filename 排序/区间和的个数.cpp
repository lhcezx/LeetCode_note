class Solution {
    vector<long> pre_sum;
    vector<long> tmp;
    int lower, upper;
    int count = 0;
public:
    void sort(vector<long>& nums, int l, int m, int r) {
        int start = m + 1, end = m + 1;             //  定义双指针
        //  这里需要注意start和end只会向右移动，因为每次循环i递增，因此对应的nums[i]是递增的, 因此我们需要更大的start元素来保证nums[start] - nums[i] >= lower
        //  同理，我们需要找到一个end使得nums[end] - nums[i] > upper, 由于i右移使得我们必须找到一个更大的end来满足这个条件  
        for (int i = l; i <= m; i++) {              //  遍历左数组的每一个元素
            while (start <= r && nums[start] - nums[i] < lower) start++;        //  找到子数组和大于等于lower的位置
            while (end <= r && nums[end] - nums[i] <= upper) end++;             //  找到子数组和大于upper的指针位置
            count += end - start;
        }

        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
            else tmp[k++] = nums[j++];
        }
        while (i <= m) tmp[k++] = nums[i++];
        while (j <= r) tmp[k++] = nums[j++];
        for (int i = 0; i < r - l + 1; i++) {
            nums[l + i] = tmp[i];
        }
    }

    void mergeSort(vector<long>& nums, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        sort(nums, l, m, r);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;
        tmp.resize(nums.size() + 1);
        pre_sum.resize(nums.size() +  1);      //  通过nums构建前缀和数组，目的是为了快速计算ij下标区间内的元素和
        for (int i = 1; i <= nums.size(); i++) {
            pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
        }
        mergeSort(pre_sum, 0, pre_sum.size() - 1);
        return count;
    }
};