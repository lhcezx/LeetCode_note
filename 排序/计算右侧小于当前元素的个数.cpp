//  由于归并排序在分左右区间时不会打乱索引顺序，会两两数组进行分割直到区间大小为1，然后递归返回，此时每个子数组都有两个元素，一个在左数组一个在右数组，通过判断左右两个值的大小将其依次排序，然后重复操作，每次操作的时候，记录左数组的指针i对应的右边比他小的元素个数j - mid - 1，该元素个数是单纯计算右数组中比他小的元素个数，因为左数组已经排序，因此左数组中i右边的元素都比i大无需判断，只需要判断右数组中的元素比i大的有多少

class Solution {
    vector<int> count;                     //  用于记录第i个元素右边比他小的值的个数
    vector<pair<int,int>> tmp;
public:
    void sort(vector<pair<int, int>>& nums, int l, int m, int r) {
        int i = l, j = m + 1;
        int k = 0;
        while (i <= m && j <= r) {
            if (nums[i].second <= nums[j].second) {
                tmp[k++] = nums[i];
                count[nums[i].first] += j - (m + 1);        //  由于j指针已经移动了j - (m + 1)步，所以说明在右半数组中比当前i小的元素个数为 j - (mid + 1)
                i++;
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= m) {
            tmp[k++] = nums[i];
            count[nums[i].first] += j - (m + 1);    //  当j指针走到尾部，此时所有剩余的i指针指向的值都比[mid + 1, right] 区间内的元素值要大，因此我们将每个元素对应右边比它大的元素加 j - (mid + 1);
            i++;
        }
        while (j <= r) tmp[k++] = nums[j++];

        for (int i = 0; i < r - l + 1; i++) {
            nums[l + i] = tmp[i]; 
        }
    }

    void mergeSort(vector<pair<int, int>>& nums, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        sort(nums, l, m, r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> pair_nums(nums.size());
        tmp.resize(nums.size());
        count.resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            pair_nums[i] = make_pair(i, nums[i]);           //  第一个元素记录每个值所在的初始索引位置，第二个记录值本身
        }
        mergeSort(pair_nums, 0, nums.size() - 1);
        return count;
    }
};