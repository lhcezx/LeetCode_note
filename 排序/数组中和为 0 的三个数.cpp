class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> tmp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) tmp.push_back(nums[i++]) ;
            else tmp.push_back(nums[j++]); 
        }
        while (i <= mid) tmp.push_back(nums[i++]);
        while (j <= right) tmp.push_back(nums[j++]);
        for (int i = 0; i < tmp.size(); i++) nums[left++] = tmp[i];
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    int getMid(vector<int>& nums, int left, int right) {
        int ref = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= ref) right--;
            nums[left] = nums[right];
            while (left < right && nums[left] < ref) left++;
            nums[right] = nums[left];
        }
        nums[left] = ref;
        return left;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = getMid(nums, left, right);
        quickSort(nums, left, mid);
        quickSort(nums, mid + 1, right);
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty() || nums.size() < 3) return res;
        quickSort(nums, 0, nums.size() - 1);   //  首先数组排序
        
        
        for (int i = 0; i < nums.size() - 2; i++) {     //  固定一个数字，然后把三指针问题变为双指针问题，二分查找结果
            int j = i + 1;
            int k = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] > 0) k--;
                else if (nums[i] + nums[j] + nums[k] < 0) j++;
                else {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    res.push_back(tmp);
                    j++;        //  找到元素j, k后 要将这两个指针分别向前和向后移动一位
                    k--;
                    while (j < k && nums[j] == nums[j-1]) j++;      //  去重操作，如果j碰到了与前面相同的元素则跳过
                    while (j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return res;
    }
};