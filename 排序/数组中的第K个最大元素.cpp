class Solution {
public:
    int random_num(vector<int>& nums, int low, int high) {      //  选取nums数组中随机一个元素作为基准，然后将基准和数组最左边元素交换
        int rand_num = rand() % (high - low + 1) + low;
        swap(nums[low], nums[rand_num]);
        return nums[low];
    }

    int getMid(vector<int>& nums, int low, int high) {          
        int pivot = random_num(nums, low, high);
        while (low < high) {
            while (low < high && nums[high] >= pivot) high--;
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot) low++;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }

    int select_quickSort(vector<int>& nums, int low, int high, int k) {         //  快速选择排序, 找到数组中第K小的元素
        if (low > high) return -1;
        int mid = getMid(nums, low, high);
        int k_num = 0;                                                          //  用于接收递归返回值的局部变量
        if (mid > k) k_num = select_quickSort(nums, low, mid - 1, k);           //  当mid > k时，说明k在mid的左边，mid可以理解为是指第mid小的元素，因为左边数字都比mid小，右边数字都比mid大
        else if (mid < k) k_num = select_quickSort(nums, mid + 1, high, k);
        else return nums[k];                                                    //  找到k时，直接返回
        return k_num;
    }

    int findKthLargest(vector<int>& nums, int k) {
        return select_quickSort(nums, 0, nums.size() - 1, nums.size() - k);      //  这里的k的argument给的是nums.size() - k, 第n-k小的元素就是第k大的元素
    }
};