// 最大堆存放nums2及其元素下标, nums1从小到大排序, 每次将nums2中最大元素和nums1中最大元素比较，若nums1大则把nums1中最大元素用来比较，否则用nums1中最小元素比较

class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int i = left, j = mid + 1;
        vector<int> tmp;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) tmp.push_back(nums[i++]);
            else tmp.push_back(nums[j++]);
        }
        
        while (i <= mid) tmp.push_back(nums[i++]);
        while (j <= right) tmp.push_back(nums[j++]);
        for (int i = 0; i < tmp.size(); i++) {
            nums[left + i] = tmp[i];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        int mid = left + (right - left) / 2;
        if (left >= right) return;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int left = 0, right = nums1.size() - 1;         //  定义左右双指针
        vector<int> res(nums1.size());
        priority_queue<pair<int, int>> max_heap;        //  创建最大堆，用于存放nums2中的元素，采用pair的形式，为的是记录元素的值及其在nums2中的下标
        for (int i = 0; i < nums2.size(); i++) {
            max_heap.push(make_pair(nums2[i], i));      //  将nums2数组中的元素和其下标放到最大堆中
        }
        mergeSort(nums1, 0, nums1.size() - 1);          //  将nums1归并排序, 排序的目的是能够快速的找到nums1中的最大值和最小值
        while (!max_heap.empty()) {
            pair<int, int> max_val = max_heap.top();    
            max_heap.pop(); 
            int val = max_val.first, idx = max_val.second;  //  找到nums2中的最大元素的位置及其下标
            if (val < nums1[right]) {
                res[idx] = nums1[right--];                  //  如果nums1中最大的元素比nums2中最大的元素大，那么将1中最大元素放到2最大元素的下标位置用于和它比较获得优势
            } else {
                res[idx] = nums1[left++];
            }
        }
        return res;
    }
};