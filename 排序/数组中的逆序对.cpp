class Solution {
    int count = 0;
public:
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> tmp;
        int l_array_idx = left, r_array_idx = mid + 1;  //  左子数组的左指针，右子数组的左指针

        while (l_array_idx <= mid && r_array_idx <= right) {        //  当左数组指针小于等于mid且右数组指针小于等于right时
            if (nums[l_array_idx] <= nums[r_array_idx]) {           //  如果左指针小于等于右指针，则将左指针放到tmp中 (从小到达排序)
                tmp.push_back(nums[l_array_idx++]);
            } else {                                                //  如果左指针大于右指针，则将右指针放入tmp，并统计逆序对个数。
                tmp.push_back(nums[r_array_idx++]);
                count += mid - l_array_idx + 1;                     //  归并排序中左数组和右数组已经分别排序完毕，因此当左指针大于右指针的值时，则左指针后的每个值都大于右指针当前值 
            }
        }
        while (l_array_idx <= mid ) tmp.push_back(nums[l_array_idx++]);       //  若左或右数组提前遍历完毕，则将剩下的数组中的数字依次放入tmp中
        while (r_array_idx <= right) tmp.push_back(nums[r_array_idx++]);
        for (int i = 0; i < right - left + 1; i++) {                          //  将已经排序好的tmp数组覆盖到仅仅排好左右数组的nums中
            nums[i + left] = tmp[i];                                          
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {        //  归并排序母函数
        if (left >= right) return;     
        int mid = (left + right) / 2;     
        mergeSort(nums, left, mid);         //  对左子数组归并排序
        mergeSort(nums, mid + 1, right);    //  对右子数组归并排序
        merge(nums, left, mid, right);      //  将左子数组和右子数组合并
    }
};