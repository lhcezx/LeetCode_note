//  高级二分
//  该题必须用nums[mid]与nums[right]判断然后收缩区间，因为nums[left]无法和nums[mid]判断，例如: [3, 4, 5, 1, 2] mid大于左边，此时应该收缩左边界，又例如[1, 2, 3, 4, 5] mid还是大于左边，但此时应该收缩右边界。我们无法判断mid在右半数组还是左半数组
//  但是mid和右边界判断，只要mid比right大，那么mid一定在左半数组，mid比right小，那么它一定在右半数组

class Solution {
public:
    int findMin(vector<int>& numbers, int left, int right) {
        int pivot = numbers[left];
        for (int i = left; i <= right; i++) {
            if (numbers[i] < pivot) return numbers[i];
        }
        return pivot;
    }

    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] < numbers[right]) {                //  当mid索引对应的值比右边小，那么它一定在右半数组，但是它可能是最小值，因此right = mid
                right = mid;
            } else if (numbers[mid] > numbers[right]) {         //  当mid索引对应的值比右边大，它一定在左半数组，并且一定不是最小值，left = mid + 1;
                left = mid + 1;
            } else {
                return findMin(numbers, left, right);           //  当mid == right的时候，我们直接从当前的left向right逐个遍历，第一个小于left的值就是最小值
            }        
        }
        return numbers[left];
    }
};