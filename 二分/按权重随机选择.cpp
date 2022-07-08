class Solution {
    vector<int> presum;
public:
    //  当用二分搜索搜索左边界的时候，如果target元素不存在，那么left指针会找到大于等于该元素的最小索引
    int binarySearch(vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                right = mid - 1;
            }
        }
        return left;
    }

    Solution(vector<int>& w) {
        int n = w.size();                               //  首先找到w中一共有多少个数字
        presum.resize(n + 1);                           //  前缀和数组
        presum[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            presum[i] = presum[i - 1] + w[i - 1];       //  每个presum[i]中
        }
    }
    
    int pickIndex() {
        int sz = presum.size();
        int num = 1 + rand() % presum[sz - 1];      //  生成的随机数在1到presum[sz - 1]范围内
        return binarySearch(presum, num) - 1;
    }
};

