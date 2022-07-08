class Solution {
public:
    int randomlize_num(vector<int>& nums, int low, int high) {
        int rand_num = rand() % (high - low + 1) + low;
        swap(nums[low], nums[rand_num]);
        return nums[low];
    }

    int getMid(vector<int>& nums, int low, int high) {
        int pivot = randomlize_num(nums, low, high);
        while (low < high) {
            while (low < high && nums[high] >= pivot) high--;
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot) low++;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int mid = getMid(nums, low, high);
        quickSort(nums, low, mid - 1);
        quickSort(nums, mid + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};