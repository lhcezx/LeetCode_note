//  根据中位数的定义，当 m+n 是奇数时，中位数是两个有序数组中的第 (m+n+1)/2 个元素，当 m+n 是偶数时，中位数是两个有序数组中的第 (m+n)/2 个元素和第 (m+n)/2+1 个元素的平均值。
//  每次从两个数组中各选第k/2小的元素，也就是索引为[k/2 - 1]的元素，比较两个数字的大小，较小的那个比它小的元素至多有k/2 - 1 + k/2 - 1 = k - 2个元素，因此从起始下标到第k小的元素k/2-1都不可能是第k小的元素. 递归排除直到k=1时，选择两个数组中剩下部分的起始位置最小的那个就是两个排序数组中第k小的元素

class Solution {
public:
    //  返回nums1[i..], nums2[j...]中第k大元素
    double recur(vector<int>& nums1, vector<int>& nums2, int i, int j, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (i == n1) return nums2[j + k - 1];
        if (j == n2) return nums1[i + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);        
        int idx1 = min(i + k / 2 - 1, n1 - 1);              //  选择从i开始，第k/2小的元素
        int idx2 = min(j + k / 2 - 1, n2 - 1);              //  选择从j开始，第k/2小的元素
        if (nums1[idx1] <= nums2[idx2]) {                   //  从第i到第idx的元素都不可能为第k大的元素
            k -= idx1 - i + 1;
            i = idx1 + 1;
        } else {
            k -= idx2 - j + 1;
            j = idx2 + 1;
        }
        return recur(nums1, nums2, i, j, k);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        //  判断两个数组中的数字总数为奇数还是偶数，若为偶数则中位数为第n1+n2/2和第(n1+n2/2)+1两个数的平均数，若为奇数则中位数直接就是第n1+n2/2大的数字
        if ((n1 + n2) % 2 == 0) {
            return (recur(nums1, nums2, 0, 0, (n1 + n2) / 2) + recur(nums1, nums2, 0, 0, (n1 + n2) / 2 + 1)) / 2;
        } else {
            return recur(nums1, nums2, 0, 0, (n1 + n2 + 1) / 2);
        }
    }
};