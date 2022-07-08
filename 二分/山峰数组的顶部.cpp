class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while(left <= right) {                                  // 最终当right = left = mid时，会执行right = mid - 1，因此要返回Left
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) right = mid - 1;       // 说明在右半数组
            else if (arr[mid] < arr[mid + 1]) left = mid + 1;   // 说明在左半数组
        }
        return left;
    }
};