//  快排
class Solution {
public:
    void random_init(vector<int>& nums, int left, int right) {
        int num = rand() % (right - left + 1) + left;
        swap(nums[left], nums[num]);
    }

    int getMid(vector<int>& nums, int left, int right) {
        random_init(nums, left, right);
        int pivot = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= pivot) right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= pivot) left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = getMid(nums, left, right);
        quickSort(nums, left, mid - 1);
        quickSort(nums, mid + 1, right);
    }
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};

//  归并排序
class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> tmp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                tmp.push_back(nums[i++]);
            } else {
                tmp.push_back(nums[j++]);
            }
        }
        while (i <= mid) tmp.push_back(nums[i++]);
        while (j <= right) tmp.push_back(nums[j++]);
        for (int i = 0; i < tmp.size(); i++) {
            nums[left + i] = tmp[i];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void sortColors(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
    }
};

//  三指针

//  本题需要保证p1始终大于等于p0，因为如果p1小于p0，则交换到p0位置的0会被p1重复替换为1，不符合题目要求
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0;             //  双指针，p0用于将i在nums遍历中遇到的0和其交换，p1用于将nums中的1与其位置交换
        for (int i = 0; i < nums.size(); i++) {
            //  当i指针遇到0时，和nums[p0]交换值
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                //  如果p0小于p1，那么p0位置原来的值一定是1，并且被换到nums[i]的位置上，因此要将nums[i]的1和nums[p1]再次交换
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                p0++;
                p1++;            
            //  当i指针遇到1时，和nums[p1]交换值，p1++         
            } else if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                p1++;
            }
        }
    }
};