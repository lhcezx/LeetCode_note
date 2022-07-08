class Solution {
    int count = 0;
    vector<int> tmp;
public:
    void sort(vector<int>& nums, int l, int m, int r) {
        int j = m + 1;
        for (int i = l; i <= m ; i++) {                     //  遍历每一个i元素, 由于i元素始终递增，j元素也是始终递增，因此当我们遍历到i, j并更新count后，i进入下一层循环i++, i++的元素比i大，因此依然满足nums[i] > 2 * nums[j]的条件，因此只需要在原来的j指针位置让它继续后移，找到不满足条件的指针位置为止
            while (j <= r && long(nums[i]) > 2 * long(nums[j])) {       //  j指针不断右移直到不满足条件
                j++;
            }
            count += j - (m + 1);
        }

        int i = l, k = 0;
        j = m + 1;
        while (i <= m && j <= r) {
            if (nums[i] < nums[j]) tmp[k++] = nums[i++];
            else tmp[k++] = nums[j++];
        }

        while (i <= m) tmp[k++] = nums[i++];
        while (j <= r) tmp[k++] = nums[j++];
        for (int i = 0; i < r - l + 1; i++) {
            nums[l + i] = tmp[i];
        }
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        sort(nums, l, m, r);
    }

    int reversePairs(vector<int>& nums) {
        tmp.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};